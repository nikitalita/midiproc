#pragma once
// C API
#include <stdint.h>
#include <stddef.h>
#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif
#ifdef __cplusplus
// define the DLL export if we're on windows


extern "C" {
#endif

// we are only creating functions which implement the processor
/**
 * @brief Process the data and serialize it to a Standard MIDI File
 * 
 * @param data The data to process
 * @param data_size The size of the data
 * @param file_extension The file extension of the data
 * @param data_out A pointer to the output data (must be freed by the caller)
 * 
 * @return The size of the output data
 * 
*/
EXPORT size_t process_and_serialize_to_smf(const uint8_t * data, size_t data_size, const char * file_extension, uint8_t ** data_out);


#ifdef __cplusplus
}
#endif
