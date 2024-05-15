#include "midiproc.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

// include time.h for time_t
#ifdef _WIN32
#include <time.h>
#else
#include <sys/time.h>
#endif

size_t get_time_in_us()
{
#ifdef _WIN32
    return clock() * 1000;
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_usec + tv.tv_sec * 1000000;
#endif
}

int main(int argc, char ** argv){
    // first argument is the file to test
    if (argc < 2)
    {
        printf("Usage: test_midiproc <file> [output_file]\n");
        return 1;
    }
    const char * test_file = argv[1];
    // get the file extension minus the dot
    const char * extension = strrchr(test_file, '.');
    if (extension == NULL)
    {
        printf("Failed to get file extension\n");
        return 1;
    }
    if (strlen(extension) < 2)
    {
        printf("Invalid file extension\n");
        return 1;
    }
    extension++;
    FILE * file = fopen(test_file, "rb");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }
    // get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    uint8_t * data = (uint8_t *) malloc(file_size);
    fread(data, 1, file_size, file);
    fclose(file);
    size_t start = get_time_in_us();
    uint8_t * data_out;
    size_t data_out_size = MIDPROC_process_and_serialize_to_smf(data, file_size, extension, &data_out);
    if (data_out_size == 0)
    {
        printf("Failed to process data\n");
        return 1;
    }
    size_t taken = get_time_in_us() - start;
    // human readable time in ms
    printf("Time taken: %ldus\n", taken);
    // remove the extension from the file name and add .mid
    char * out_file_name;
    if (argc > 2)
    {
        // copy it
        out_file_name = (char *) malloc(strlen(argv[2]) + 1);
        strncpy(out_file_name, argv[2], strlen(argv[2]));
        out_file_name[strlen(argv[2])] = '\0';
    } else {
        out_file_name = (char *) malloc(strlen(test_file) - strlen(extension) + 5);
        strncpy(out_file_name, test_file, strlen(test_file) - strlen(extension));
        strncpy(out_file_name + strlen(test_file) - strlen(extension), "mid", 3);
        out_file_name[strlen(test_file) - strlen(extension) + 4] = '\0';
    }
    FILE * out_file = fopen(out_file_name, "wb");
    if (out_file == NULL)
    {
        printf("Failed to open output file\n");
        return 1;
    }
    fwrite(data_out, 1, data_out_size, out_file);
    fclose(out_file);
    printf("Wrote output to %s\n", out_file_name);
    free(out_file_name);
    free(data);
    free(data_out);
    return 0;
}
