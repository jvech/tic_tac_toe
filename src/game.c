#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "game.h"


int game_menu()
{
    initscr();
    clear();
    mvaddstr(0, 0,"Welcome to Tic Tac Toe Game");
    int opt;
    opt = 500;
    do {
        move(2, 0);
        addstr("1) new game\n");
        addstr("2) choose player names\n");
        addstr("3) exit the game\n");
        addstr("\topt: ");
        opt = (int)getch() - '0';
        refresh();
    } while(opt < 1 || opt > 3);
    endwin();
    return opt;
}

void game_match(struct player p1, struct player p2)
{
    /*
     * Match game of tic tac toe
     */
    char board[3][3];
    struct player players[2];
    int turn, pos[2];
    int input;

    turn = 0;
    pos[0] = pos[1] = 0;
    players[0] = p1;
    players[1] = p2;

    board_init(board);

    initscr();

    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    //start_color();
    clear();
    mvprintw(3, 15, "%s (%c)", p1.name, p1.symbol);
    mvprintw(5, 15, "%s (%c)", p2.name, p2.symbol);
    while (!board_filled(board, '-')) {
        move(0, 0);
        deleteln();
        insertln();
        mvprintw(0, 2, "%s Turn", players[turn].name);
        do {
            board_show(board, 2, 2, pos);
            input = getch();
            switch (input) {
                case KEY_UP:
                case 'k':
                    pos[0]--;
                    break;
                case KEY_DOWN:
                case 'j':
                    pos[0]++;
                    break;
                case KEY_LEFT:
                case 'h':
                    pos[1]--;
                    break;
                case KEY_RIGHT:
                case 'l':
                    pos[1]++;
                    break;
                default:
                    break;
            }
            if (pos[0] == 3) pos[0] = 0;
            else if (pos[0] == -1) pos[0] = 2;
            if (pos[1] == 3) pos[1] = 0;
            else if (pos[1] == -1) pos[1] = 2;
        } while (input != ' ' || board[pos[0]][pos[1]] != '-');

        input = KEY_CLEAR;
        board_update(board, pos, players[turn].symbol);
        refresh();
        if (board_check(board, players[turn].symbol)) {
            mvprintw(8, 0, "Congratulations player %s, you have won\n", players[turn].name);
            getch();
            endwin();
            return;
        }
        turn = !turn;
    }
    mvprintw(8, 0, "No one won it's a tie\n");
    getch();
    curs_set(2);
    echo();
    endwin();
}

void game_rename(struct player* p1, struct player* p2)
{
    char name1[20], name2[20];
    char symbol1, symbol2;

    do {
        printf("select player1: 'name' 'symbol': ");
        scanf("%s %c", name1, &symbol1);
        if (symbol1 == '-')
            printf("\nYou can't select '-' symbol Try it again\n");
    } while(symbol1 == '-');
    

    do {
        printf("select player2: 'name' 'symbol': ");
        scanf("%s %c", name2, &symbol2);
        if (symbol2 == '-')
            printf("\nYou can't select '-' symbol Try it again\n");
        if (symbol1 == symbol2)
            printf("\nyou can't select the same symbol of player1 Try it again\n");
    } while(symbol2 == '-' || symbol2 == symbol1);

    p1->symbol = symbol1;
    p2->symbol = symbol2;
    int i;
    for (i = 0; i < 20; i++) {
        (p1->name)[i] = name1[i];
        (p2->name)[i] = name2[i];
    }
}
