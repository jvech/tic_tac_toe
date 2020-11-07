#include<stdio.h>

struct player {
    char name[20];
    char symbol;
};

int game_menu();
void game_match(struct player, struct player);
void game_rename(struct player * , struct player *);
