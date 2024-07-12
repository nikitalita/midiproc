#include "MIDIProcessor.h"
#include "MIDIContainer.h"
#include "midiproc.h"

EXTERN size_t MIDPROC_process_and_serialize_to_smf(const uint8_t * data, size_t data_size, const char * file_extension, uint8_t ** data_out)
{
    // convert the data to a vector
    std::vector<uint8_t> data_vector(data, data + data_size);
    MIDIContainer * container = new MIDIContainer();
    if (!MIDIProcessor::Process(data_vector, file_extension, *container))
    {
        delete container;
        return 0;
    }
    // create a std::vector to hold the serialized data on the heap
    std::vector<uint8_t> * serialized_container = new std::vector<uint8_t>();

    container->SerializeAsSMF(*serialized_container);
    size_t size = serialized_container->size();
    // copy the serialized data to the output buffer
    *data_out = new uint8_t[serialized_container->size()];
    std::copy(serialized_container->begin(), serialized_container->end(), *data_out);
    delete serialized_container;
    // free the memory
    delete container;
    return size;
}

EXTERN HMIDIContainer MIDPROC_Container_Create()
{
    MIDIContainer * container = new MIDIContainer();
    return static_cast<HMIDIContainer>(container);
}

EXTERN void MIDPROC_Container_Delete(HMIDIContainer processor)
{
    MIDIContainer * container = static_cast<MIDIContainer *>(processor);
    delete container;
}

EXTERN bool MIDPROC_Process(const uint8_t * data, size_t data_size, const char * file_extension, HMIDIContainer container)
{
    std::vector<uint8_t> data_vector(data, data + data_size);
    if (!MIDIProcessor::Process(data_vector, file_extension, *container)){
        return false;
    }
    return true;
}

EXTERN void MIDPROC_Container_SerializeAsSMF(HMIDIContainer container, uint8_t ** data_out, size_t * data_out_size)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    std::vector<uint8_t> * serialized_container = new std::vector<uint8_t>();
    c->SerializeAsSMF(*serialized_container);
    *data_out = new uint8_t[serialized_container->size()];
    std::copy(serialized_container->begin(), serialized_container->end(), *data_out);
    *data_out_size = serialized_container->size();
    delete serialized_container;
}

EXTERN uint32_t MIDPROC_Container_GetFormat(HMIDIContainer container)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    return c->GetFormat();
}

EXTERN uint32_t MIDPROC_Container_GetTrackCount(HMIDIContainer container)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    return c->GetTrackCount();
}

EXTERN uint32_t MIDPROC_Container_GetChannelCount(HMIDIContainer container, size_t subSongIndex)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    return c->GetChannelCount(subSongIndex);
}

EXTERN uint32_t MIDPROC_Container_GetLoopBeginTimestamp(HMIDIContainer container, size_t subSongIndex, bool ms)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    return c->GetLoopBeginTimestamp(subSongIndex, ms);
}

EXTERN uint32_t MIDPROC_Container_GetLoopEndTimestamp(HMIDIContainer container, size_t subSongIndex, bool ms)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    return c->GetLoopEndTimestamp(subSongIndex, ms);
}

EXTERN uint32_t MIDPROC_Container_GetDuration(HMIDIContainer container, size_t subSongIndex, bool ms)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    return c->GetDuration(subSongIndex, ms);
}

EXTERN size_t MIDPROC_Container_GetSubSongCount(HMIDIContainer container)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    return c->GetSubSongCount();
}

EXTERN size_t MIDPROC_Container_GetSubSong(HMIDIContainer container, size_t index)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    return c->GetSubSong(index);
}

EXTERN void MIDPROC_Container_PromoteToType1(HMIDIContainer container)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    c->PromoteToType1();
}

EXTERN void MIDPROC_Container_DetectLoops(HMIDIContainer container, bool detectXMILoops, bool detectMarkerLoops, bool detectRPGMakerLoops, bool detectTouhouLoops)
{
    MIDIContainer * c = static_cast<MIDIContainer *>(container);
    c->DetectLoops(detectXMILoops, detectMarkerLoops, detectRPGMakerLoops, detectTouhouLoops);
}
