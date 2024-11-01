#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"

typedef struct Playlist {
    Song *head;
    Song *current;
} Playlist;

void add_song(Playlist *playlist, const char *file_path, const char *title, const char *genre);
void play_next_song(Playlist *playlist);
void play_previous_song(Playlist *playlist);
void switch_to_song(Playlist *playlist, const char *title);
void display_songs_by_genre(Playlist *playlist, const char *genre);

#endif // PLAYLIST_H


