#include"board.h"
#include<stdio.h>

void board_init(char x[3][3]){
    /*
     * x -> the game board to init
     */
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            x[i][j] = '-';
        }
    }
}

void board_show(char x[3][3]){
    /*
     * x -> the game board to show
     */
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%c\t", x[i][j]);
        }
        printf("\n");
    }
}

void board_update(char x[3][3], int pos[2], char value){
    /*
     * x -> the game board to show
     * pos -> [row, column]
     */
    x[pos[0]][pos[1]] = value;
}

int board_check(char x[3][3], char symbol){
    /*
     * inputs:
     *      x -> game board
     *      symbol -> player symbol
     */
    int i;
    if (diags_check(x, symbol))
        return 1;

    for(i=0; i<3; i++){
        if(row_check(x, symbol, i) || col_check(x, symbol, i))
            return 1;
    }
    return 0;
}

int board_filled(char x[3][3], char symbol){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(x[i][j] == symbol)
                return 0;
        }
    }
    return 1;
}
        

int row_check(char x[3][3], char symbol, int row){
    int col, count;
    count = 0;
    for(col=0; col<3; col++){
        if (x[row][col] == symbol)
            count++;
    }
    if (count == 3)
        return 1;
    return 0;
}

int col_check(char x[3][3], char symbol, int col){
    int row, count;
    count = 0;
    for(row=0; row<3; row++){
        if (x[row][col] == symbol)
            count++;
    }
    if (count == 3)
        return 1;
    return 0;
}

int diags_check(char x[3][3], char symbol){
    int i, count, count1;
    count = count1 = 0;

    for(i=0; i<3; i++){
        if(x[i][i] == symbol)
            count++;
        if(x[i][2-i] == symbol)
            count1++;
    }
    if (count==3 || count1==3)
        return 1;
    return 0;
}
