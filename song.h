#ifndef SONG_H
#define SONG_H

#include <SDL2/SDL.h>

typedef struct Song {
    char file_path[256];
    char title[100];
    char genre[50];
    struct Song *next;
    struct Song *prev;
} Song;

void play_song(const char *file_path);

#endif // SONG_H

