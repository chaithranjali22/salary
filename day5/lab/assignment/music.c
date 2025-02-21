#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[256];
    struct Song *next;
} Song;

typedef struct {
    Song *current_song;
} Playlist;

void initPlaylist(Playlist *playlist) {
    playlist->current_song = NULL;
}

void addSong(Playlist *playlist, const char *title) {
    Song *new_song = (Song *)malloc(sizeof(Song));
    if (new_song == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(new_song->title, title);
    new_song->next = NULL;

    if (playlist->current_song == NULL) {
        new_song->next = new_song; // Circular link for the first song
        playlist->current_song = new_song;
    } else {
        Song *last_song = playlist->current_song;
        while (last_song->next != playlist->current_song) {
            last_song = last_song->next;
        }
        last_song->next = new_song;
        new_song->next = playlist->current_song;
    }
}

void playNextSong(Playlist *playlist) {
    if (playlist->current_song == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    playlist->current_song = playlist->current_song->next;
    printf("Next Song: %s\n", playlist->current_song->title);
}

void displayCurrentSong(Playlist *playlist) {
    if (playlist->current_song == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    printf("Current Song: %s\n", playlist->current_song->title);
}

void freePlaylist(Playlist *playlist) {
    if (playlist->current_song == NULL) {
        return;
    }

    Song *current = playlist->current_song;
    Song *next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != playlist->current_song);

    playlist->current_song = NULL;
}

int main() {
    Playlist playlist;
    initPlaylist(&playlist);

    addSong(&playlist, "Song A");
    addSong(&playlist, "Song B");
    addSong(&playlist, "Song C");

    displayCurrentSong(&playlist);
    playNextSong(&playlist);
    playNextSong(&playlist);
    playNextSong(&playlist);
    playNextSong(&playlist);
    displayCurrentSong(&playlist);

    freePlaylist(&playlist);

    return 0;
}
