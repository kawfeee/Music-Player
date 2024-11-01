HOW TO RUN :-
1) first go the the program directory
2) open terminal
3) gcc -Wall -g -I./source/include -L./source/lib -o music_playlist.exe main.c playlist.c song.c -lmingw32 -lSDL2main -lSDL2
press enter
4) ./music_playlist.exe
press enter

SOFTWARES NEEDED:-
1) MinGW
2) SDL2 (for sound playback)

PROCEDURE TO ADD A NEW SONG:-
1) copy and paste the music file in "music" folder of the project
2) run the project and enter 6 in menu of main function to add a song
3) enter the path of new song to add (music/new_song.wav)
4) enter the title of the song
5) enter the genre of the song
6) press enter
7) try running by title (it should work)
8) now in main file insert the following line where the other add_song statements are present :- add_song(&playlist, "music/songfile_name.wav", "song_title", "genre");
9) you are good to go



