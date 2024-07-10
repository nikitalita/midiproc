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

#include <SDL_mixer_ext.h>
#include <SDL.h>
#define OUTPUT_QUALITY 4
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
static SDL_AudioDeviceID audioDevice = 0;
static Mix_CommonMixer_t mixer = NULL;

void audioCallback(void *userdata, Uint8 *stream, int len)
{
    mixer(userdata, stream, len);
    Sint16 *const samples = (Sint16 *)stream;
	const int samplesCount = len / sizeof (Sint16);

}
Mix_Chunk * chunk;
int samples_remaining = 0;

void reload_sample_queue(){
    // take the chu
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


    // play the midi file
    if(SDL_Init(SDL_INIT_AUDIO) == -1)
    {
        printf("Failed to initialize SDL\n");
        return 1;
    }
    if (!Mix_Init(MIX_INIT_MID)){
        printf("Failed to initialize SDL_mixer\n");
        return 1;
    }
    SDL_AudioSpec ask, got;

	ask.freq = 11025 * OUTPUT_QUALITY;
	ask.format = AUDIO_S16SYS;
	ask.channels = 1;
	ask.samples = 256 * OUTPUT_QUALITY; // ~23 ms
	ask.callback = audioCallback;

	int allowedChanges = SDL_AUDIO_ALLOW_FREQUENCY_CHANGE;
#if SDL_VERSION_ATLEAST(2, 0, 9)
	allowedChanges |= SDL_AUDIO_ALLOW_SAMPLES_CHANGE;
#endif
    audioDevice = SDL_OpenAudioDevice(/*device*/ NULL, /*iscapture*/ 0, &ask, &got, allowedChanges);

    // if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 512) < 0)
    if (audioDevice == 0)
    {
        printf("Failed to open audio\n");
        return 1;
    }
    if (Mix_InitMixer(&got, SDL_FALSE) != 0)
    {
        printf("Failed to initialize mixer\n");
        return 1;
    }
    if (Mix_SetSoundFonts("/Users/andyvand/Downloads/FluidR3 GM.SF2") == 0)
    {
        printf("Failed to set soundfont\n");
        return 1;
    }
    mixer = Mix_GetGeneralMixer();
    if (mixer == NULL)
    {
        printf("Failed to get mixer\n");
        return 1;
    }
    // copy the header from the output data
    uint8_t header[14];
    memcpy(header, data_out, 14);
    chunk = Mix_LoadWAV("/Users/andyvand/Downloads/gun-gunshot-02.wav");
    if (chunk == NULL)
    {
        printf("Failed to load chunk\n");
        return 1;
    }
    samples_remaining = chunk->alen / 2;
    
    Mix_Music * music = Mix_LoadMUSType_RW_ARG(SDL_RWFromConstMem(data_out, data_out_size), MUS_MID, 1, "s4;p512;");
    if (music == NULL)
    {
        printf("Failed to load music\n");
        return 1;
    }
    if (Mix_PlayMusic(music, 1) != 0)
    {
        printf("Failed to play music\n");
        return 1;
    }
    SDL_PauseAudioDevice(audioDevice, 0);
    // wait for the music to finish
    
    while (Mix_PlayingMusic())
    {
        // uint32_t delay = (chunk->alen / (44100 * 2 * 2)) * 1000;
        SDL_Delay(100);
        // Mix_PlayChannel(-1, chunk, 0);
    }
    return 0;
}
