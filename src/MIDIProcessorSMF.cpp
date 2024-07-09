
/** $VER: MIDIProcessorSMF.cpp (2023.11.01) Standard MIDI File **/
#include "MIDIProcessor.h"

#include "../compat/common_compat.h"
#include "../compat/string_compat.h"

  const uint8_t SysExUseForRhythmPartCh16[] = { 0xF0, 0x41, 0x10, 0x42, 0x12, 0x40, 0x1F, 0x15, 0x02, 0x0A, 0xF7 }; // Use channel 16 for rhythm.

bool MIDIProcessor::IsSMF(std::vector<uint8_t> const & data)
{
    if (data.size() < 18)
        return SetLastErrorCode(InsufficientData);

    if (::memcmp(&data[0], "MThd", 4) != 0)
        return SetLastErrorCode(SMFBadHeaderChunkType);

    if (data[4] != 0 || data[5] != 0 || data[6] != 0 || data[7] != 6)
        return SetLastErrorCode(SMFBadHeaderChunkSize);

    int Format = (data[8] << 8) | data[9];

    if (Format > 2)
        return SetLastErrorCode(SMFBadHeaderFormat);

    int TrackCount = (data[10] << 8) | data[11];

    if ((TrackCount == 0) || ((Format == 0) && (TrackCount != 1)))
        return SetLastErrorCode(SMFBadHeaderTrackCount);

    if (data[12] == 0 && data[13] == 0)
        return SetLastErrorCode(SMFBadHeaderTimeDivision);

    if (::memcmp(&data[14], "MTrk", 4) != 0)
        return SetLastErrorCode(SMFUnknownChunkType);

    return true;
}

bool MIDIProcessor::ProcessSMF(std::vector<uint8_t> const & data, MIDIContainer & container)
{
    SetLastErrorCode(MENone);

    if (data.size() < 18)
        return SetLastErrorCode(InsufficientData);

    if (::memcmp(&data[0], "MThd", 4) != 0)
        return SetLastErrorCode(SMFBadHeaderChunkType);

    if (data[4] != 0 || data[5] != 0 || data[6] != 0 || data[7] != 6)
        return SetLastErrorCode(SMFBadHeaderChunkSize);

    int Format = (data[8] << 8) | data[9];

    if (Format > 2)
        return SetLastErrorCode(SMFBadHeaderFormat);

    int TrackCount = (data[10] << 8) | data[11];

    if ((TrackCount == 0) || ((Format == 0) && (TrackCount != 1)))
        return SetLastErrorCode(SMFBadHeaderTrackCount);

    int TimeDivision = (data[12] << 8) | data[13];

    if (TimeDivision == 0)
        return SetLastErrorCode(SMFBadHeaderTimeDivision);

    container.Initialize((uint32_t) Format, (uint32_t) TimeDivision);

    std::vector<uint8_t>::const_iterator Data = data.begin() + 14;
    std::vector<uint8_t>::const_iterator Tail = data.end();

    for (int i = 0; i < TrackCount; ++i)
    {
        if (Tail - Data < 8)
            return SetLastErrorCode(InsufficientData);

        uint32_t ChunkSize = (uint32_t)((Data[4] << 24) | (Data[5] << 16) | (Data[6] << 8) | Data[7]);

        if (::memcmp(&Data[0], "MTrk", 4) == 0)
        {
            if (Tail - Data < (std::ptrdiff_t) (8 + ChunkSize))
                return SetLastErrorCode(InsufficientData);

            Data += 8;

            std::vector<uint8_t>::const_iterator ChunkTail = Data + (int) ChunkSize;

            if (!ProcessSMFTrack(Data, ChunkTail, container, true))
                return false;

            Data = ChunkTail; // In case no all track data gets used.
        }
        // Skip unknown chunks in the stream.
        else
        {
            if (Tail - Data < (std::ptrdiff_t) (8 + ChunkSize))
                return SetLastErrorCode(InsufficientData);

            Data += (int64_t)(8) + ChunkSize;

            continue;
        }
    }

    return true;
}

bool MIDIProcessor::ProcessSMFTrack(std::vector<uint8_t>::const_iterator & data, std::vector<uint8_t>::const_iterator tail, MIDIContainer & container, bool trackNeedsEndMarker)
{
    MIDITrack Track;

    uint32_t Timestamp = 0;
    uint8_t LastStatusCode = 0xFF;

    uint32_t SysExSize = 0;
    uint32_t SysExTimestamp = 0;

    std::vector<uint8_t> Temp(3);

    bool DetectedPercussionText = false;

    for (;;)
    {
        if (!trackNeedsEndMarker && (data == tail))
            break;

        int DeltaTime = DecodeVariableLengthQuantity(data, tail);

        if (data == tail)
            return SetLastErrorCode(InsufficientData);

        if (DeltaTime < 0)
            DeltaTime = -DeltaTime; // "Encountered negative delta: " << delta << "; flipping sign."

        Timestamp += DeltaTime;

        uint32_t BytesRead = 0;

        uint8_t StatusCode = *data++;

        if (StatusCode < NoteOff)
        {
            if (LastStatusCode == 0xFF)
                return SetLastErrorCode(SMFBadFirstMessage);

            Temp.resize(3);

            Temp[BytesRead++] = StatusCode;

            StatusCode = LastStatusCode;
        }

        if (StatusCode < SysEx)
        {
            if (SysExSize > 0)
            {
                Track.AddEvent(MIDIEvent(SysExTimestamp, Extended, 0, (unsigned char *)(&Temp[0]/*.data()*/), SysExSize));
                SysExSize = 0;
            }

            LastStatusCode = StatusCode;

            if (!trackNeedsEndMarker && ((StatusCode & 0xF0) == PitchBendChange))
                continue;

            if (BytesRead == 0)
            {
                if (data == tail)
                    return SetLastErrorCode(InsufficientData);

                Temp.resize(3);

                Temp[0] = *data++;
                BytesRead = 1;
            }

            switch (StatusCode & 0xF0)
            {
                case ProgramChange:
                case ChannelPressureAftertouch:
                    break;

                default:
                    if (data == tail)
                        return SetLastErrorCode(InsufficientData);

                    Temp[BytesRead++] = *data++;
            }

            uint32_t ChannelNumber = (uint32_t) (StatusCode & 0x0F);

            // Assign percussion to channel 16 if it's first message was preceded with meta data containing the word "drum".
            {

                if ((ChannelNumber == 0x0F) && DetectedPercussionText)
                {
                    Track.AddEvent(MIDIEvent(0, Extended, 0, SysExUseForRhythmPartCh16, _countof(SysExUseForRhythmPartCh16)));

                    container.SetExtraPercussionChannel(ChannelNumber);

                    DetectedPercussionText = false;
                }
            }

            Track.AddEvent(MIDIEvent(Timestamp, (EventType) ((StatusCode >> 4) - 8), ChannelNumber, (unsigned char *)(&Temp[0]/*.data()*/), BytesRead));
        }
        else
        if (StatusCode == SysEx)
        {
            if (SysExSize > 0)
            {
                Track.AddEvent(MIDIEvent(SysExTimestamp, Extended, 0, (unsigned char *)(&Temp[0]/*.data()*/), SysExSize));
                SysExSize = 0;
            }

            int Size = DecodeVariableLengthQuantity(data, tail);

            if (Size < 0)
                return SetLastErrorCode(InvalidSysExMessage);

            if (Size > tail - data)
                return SetLastErrorCode(InsufficientData);

            {
                Temp.resize((size_t) (Size + 1));

                Temp[0] = SysEx;

                std::copy(data, data + Size, Temp.begin() + 1);
                data += Size;

                SysExSize = (uint32_t) (Size + 1);
                SysExTimestamp = Timestamp;
            }
        }
        else
        if (StatusCode == SysExEnd)
        {
            if (SysExSize == 0)
                return SetLastErrorCode(InvalidSysExEndMessage);

            // Add the SysEx continuation to the current SysEx message
            int Size = DecodeVariableLengthQuantity(data, tail);

            if (Size < 0)
                return SetLastErrorCode(InvalidSysExMessageContinuation);

            if (Size > tail - data)
                return SetLastErrorCode(InsufficientData);

            {
                Temp.resize((size_t) SysExSize + Size);

                std::copy(data, data + Size, Temp.begin() + (int) SysExSize);
                data += Size;

                SysExSize += Size;
            }
        }
        else
        if (StatusCode == MetaData)
        {
            if (SysExSize > 0)
            {
                Track.AddEvent(MIDIEvent(SysExTimestamp, Extended, 0, (unsigned char *)(&Temp[0]/*.data()*/), SysExSize));
                SysExSize = 0;
            }

            if (data == tail)
                return SetLastErrorCode(InvalidMetaDataMessage);

            uint8_t MetaDataType = *data++;

            if (MetaDataType > SequencerSpecific)
                return SetLastErrorCode(InvalidMetaDataMessage);

            int Size = DecodeVariableLengthQuantity(data, tail);

            if (Size < 0)
                return SetLastErrorCode(InvalidMetaDataMessage);

            if (Size > tail - data)
                return SetLastErrorCode(InsufficientData);

            // Remember when the track or instrument name contains the word "drum". We'll need it later.
            if ((MetaDataType == TextE) || (MetaDataType == TrackName) || (MetaDataType == InstrumentName))
            {
                const char * p = (const char *) &data[0];

                for (int n = Size; n > 3; --n, p++)
                {
                    if (::_strnicmp(p, "drum", 4) == 0)
                    {
                        DetectedPercussionText = true;
                        break;
                    }
                }
            }

            {
                Temp.resize((size_t)(Size + 2));

                Temp[0] = MetaData;
                Temp[1] = MetaDataType;

                std::copy(data, data + Size, Temp.begin() + 2);
                data += Size;

                Track.AddEvent(MIDIEvent(Timestamp, Extended, 0, (unsigned char *)(&Temp[0]/*.data()*/), (size_t) (Size + 2)));

                if (MetaDataType == EndOfTrack) // Mandatory, Marks the end of the track.
                {
                    trackNeedsEndMarker = true;
                    break;
                }
            }
        }
        else
        if ((SysExEnd < StatusCode) && (StatusCode < MetaData)) // Sequencer specific events, single byte.
        {
            Temp[0] = StatusCode;

            Track.AddEvent(MIDIEvent(Timestamp, Extended, 0, (unsigned char *)(&Temp[0]/*.data()*/), 1));
        }
        else
            return SetLastErrorCode(UnknownStatusCode);
    }

    if (!trackNeedsEndMarker)
    {
        Temp[0] = MetaData;
        Temp[1] = EndOfTrack;

        Track.AddEvent(MIDIEvent(Timestamp, Extended, 0, (unsigned char *)(&Temp[0]/*.data()*/), 2));
    }

    container.AddTrack(Track);

    return true;
}
