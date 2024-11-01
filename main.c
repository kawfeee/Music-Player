#include <stdio.h>
#include <string.h>
#include "playlist.h"

void display_menu() {
    printf("\nMusic Playlist System\n");
    printf("1. Play Current Song\n");
    printf("2. Play Previous Song\n");
    printf("3. Play Next Song\n");
    printf("4. Switch to a Song by Title\n");
    printf("5. Display Songs by Genre\n");
    printf("6. Add New Song\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Updated main function with SDL-compatible parameters
int main(int argc, char *argv[]) {
    Playlist playlist;
    playlist.head = NULL;
    playlist.current = NULL;

    // Adding songs to the playlist
    add_song(&playlist, "music/song1.wav", "Song 1", "Pop");
    add_song(&playlist, "music/song2.wav", "Song 2", "Rock");
    add_song(&playlist, "music/song3.wav", "Song 3", "Pop");
    add_song(&playlist, "music/song4.wav", "Song 4", "Pop");

    int choice;
    char title[100];
    char genre[100];

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Play current song
                if (playlist.current != NULL) {
                    printf("Playing current song: %s\n", playlist.current->title);
                    play_song(playlist.current->file_path);
                } else {
                    printf("No song selected to play.\n");
                }
                break;

            case 2:  // Play previous song
                printf("Playing the previous song:\n");
                play_previous_song(&playlist);
                break;

            case 3:  // Play next song
                printf("Playing the next song:\n");
                play_next_song(&playlist);
                break;

            case 4:  // Switch to a song by title
                printf("Enter the title of the song to switch to: ");
                scanf(" %[^\n]%*c", title);  // Read full line with spaces
                switch_to_song(&playlist, title);
                break;

            case 5:  // Display songs by genre
                printf("Enter genre to display songs: ");
                scanf(" %[^\n]%*c", genre);  // Read full line with spaces
                display_songs_by_genre(&playlist, genre);
                break;


            case 6:  // Add a new song
                printf("Enter the file path of the new song (e.g., music/new_song.wav): ");
                char file_path[100];
                scanf(" %[^\n]%*c", file_path);

                printf("Enter the title of the new song: ");
                char new_title[100];
                scanf(" %[^\n]%*c", new_title);

                printf("Enter the genre of the new song: ");
                char new_genre[100];
                scanf(" %[^\n]%*c", new_genre);

                add_song(&playlist, file_path, new_title, new_genre);
                printf("Song '%s' added to the playlist.\n", new_title);
                break;

            case 7:  // Exit
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
