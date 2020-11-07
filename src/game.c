#include<stdio.h>
#include<stdlib.h>
#include"board.h"
#include"game.h"


int game_menu(){
    printf("\n\nWelcome to Tic Tac Toe Game\n\n");
    int opt;
    opt = 500;
    do{
    printf("1) new game\n");
    printf("2) choose player names\n");
    printf("3) exit the game\n");
    printf("\topt: ");
    scanf("%d", &opt);
    }while(opt < 1 || opt > 3);
    return opt;
}

void game_match(struct player p1, struct player p2){
    /*
     * Match game of tic tac toe
     */
    char board[3][3];
    struct player players[2];
    int turn, pos[2];

    turn = 0;
    players[0] = p1;
    players[1] = p2;

    board_init(board);
    while(!board_filled(board, '-')){
        system("clear");
        board_show(board);
        do{
            printf("%s (%c) select your position: 'x' 'y': ", 
                    players[turn].name, players[turn].symbol);
            scanf("%d %d", &pos[0], &pos[1]);
            if(pos[0]<0 || pos[0]>2 || pos[1]<0 || pos[1]>2)
                printf("x or y are in invalid ranges. Try Again\n");
            if(board[pos[0]][pos[1]] != '-' && (pos[0] >= 0 && pos[1] < 3))
                printf("That position is already used. Try Again\n");
        }while(pos[0]<0 || pos[0]>2 || pos[1]<0 || pos[1]>2 || 
                board[pos[0]][pos[1]] != '-');
        board_update(board, pos, players[turn].symbol);
        if(board_check(board,players[turn].symbol)){
            board_show(board);
            printf("\nCongratulations %s you have won", players[turn].name);
            return;
        }
        turn = !turn;
    }
    system("clear");
    board_show(board);
    printf("No one has won the game, it's a tie bastards\n");
}

void game_rename(struct player* p1, struct player* p2){
    char name1[20], name2[20];
    char symbol1, symbol2;

    do{
        printf("select player1: 'name' 'symbol': ");
        scanf("%s %c", name1, &symbol1);
    if(symbol1 == '-')
        printf("\nYou can't select '-' symbol Try it again\n");
    }while(symbol1 == '-');
    

    do{
        printf("select player2: 'name' 'symbol': ");
        scanf("%s %c", name2, &symbol2);
    if(symbol2 == '-')
        printf("\nYou can't select '-' symbol Try it again\n");
    if(symbol1 == symbol2)
        printf("\nyou can't select the same symbol of player1 Try it again\n");
    }while(symbol2 == '-' || symbol2 == symbol1);

    p1->symbol = symbol1;
    p2->symbol = symbol2;
    int i;
    for(i=0; i<20; i++){
        (p1->name)[i] = name1[i];
        (p2->name)[i] = name2[i];
    }
}
