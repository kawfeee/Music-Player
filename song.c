#include "song.h"
#include <stdio.h>

void play_song(const char *file_path) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return;
    }

    SDL_AudioSpec wav_spec;
    Uint32 wav_length;
    Uint8 *wav_buffer;

    if (SDL_LoadWAV(file_path, &wav_spec, &wav_buffer, &wav_length) == NULL) {
        printf("Could not open audio file %s: %s\n", file_path, SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_AudioDeviceID device_id = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
    if (device_id == 0) {
        printf("SDL could not open audio device! SDL Error: %s\n", SDL_GetError());
        SDL_FreeWAV(wav_buffer);
        SDL_Quit();
        return;
    }

    SDL_QueueAudio(device_id, wav_buffer, wav_length);
    SDL_PauseAudioDevice(device_id, 0);

    SDL_Delay((wav_length / wav_spec.freq) * 1000);

    SDL_CloseAudioDevice(device_id);
    SDL_FreeWAV(wav_buffer);
    SDL_Quit();
}
