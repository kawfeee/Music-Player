#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "song.h"

// Function to add a song to the playlist
void add_song(Playlist *playlist, const char *file_path, const char *title, const char *genre) {
    Song *new_song = malloc(sizeof(Song));
    strncpy(new_song->file_path, file_path, sizeof(new_song->file_path) - 1);
    strncpy(new_song->title, title, sizeof(new_song->title) - 1);
    strncpy(new_song->genre, genre, sizeof(new_song->genre) - 1);
    new_song->next = NULL;
    new_song->prev = NULL;

    if (playlist->head == NULL) {
        playlist->head = new_song;
        playlist->current = new_song;
    } else {
        Song *last = playlist->head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_song;
        new_song->prev = last;
    }
}

// Function to play the next song in the playlist
void play_next_song(Playlist *playlist) {
    if (playlist->current == NULL || playlist->current->next == NULL) {
        printf("No next song in the playlist.\n");
        return;
    }
    playlist->current = playlist->current->next;
    play_song(playlist->current->file_path);
}

// Function to play the previous song in the playlist
void play_previous_song(Playlist *playlist) {
    if (playlist->current == NULL || playlist->current->prev == NULL) {
        printf("No previous song in the playlist.\n");
        return;
    }
    playlist->current = playlist->current->prev;
    play_song(playlist->current->file_path);
}

// Function to switch to a specific song by title
void switch_to_song(Playlist *playlist, const char *title) {
    Song *song = playlist->head;
    while (song != NULL) {
        if (strcmp(song->title, title) == 0) {
            playlist->current = song;
            play_song(song->file_path);
            return;
        }
        song = song->next;
    }
    printf("Song with title '%s' not found in the playlist.\n", title);
}

// Function to display songs by genre
void display_songs_by_genre(Playlist *playlist, const char *genre) {
    Song *song = playlist->head;
    int found = 0;
    printf("Songs in genre '%s':\n", genre);
    while (song != NULL) {
        if (strcmp(song->genre, genre) == 0) {
            printf(" - %s\n", song->title);
            found = 1;
        }
        song = song->next;
    }
    if (!found) {
        printf("No songs found in genre '%s'.\n", genre);
    }
}


