#include "midiproc.h"
#include "MIDIProcessor.h"
#include "MIDIContainer.h"

size_t process_and_serialize_to_smf(const uint8_t * data, size_t data_size, const char * file_extension, uint8_t ** data_out)
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
