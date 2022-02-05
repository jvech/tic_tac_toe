#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "game.h"

int main()
{
    struct player p1, p2;
    int opt;
    opt = 0;

    game_rename(&p1, &p2);
    while (opt != 2) {
        //system("clear");
        opt = game_menu();
        switch (opt) {
            case 0:
                game_match(p1, p2);
                break;
            case 1:
                system("clear");
                printf("2) choose player names\n");
                game_rename(&p1, &p2);
                break;
            case 2:
                break;

            default:
                break;
        }
    }

    return 0;
}
