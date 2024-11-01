# Makefile for music playlist system with SDL2
# Makefile for music playlist system with SDL2
CC = gcc
CFLAGS = -Wall -g -I./source/include   # Path to SDL2 include directory
LIBS = -L./source/lib -lmingw32 -lSDL2main -lSDL2   # Path to SDL2 library directory

TARGET = music_playlist.exe

all: $(TARGET)

$(TARGET): main.c playlist.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c playlist.c $(LIBS)

clean:
	rm -f $(TARGET)
