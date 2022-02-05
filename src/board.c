#include <ncurses.h>
#include "board.h"

void board_init(char board[3][3])
{
    /*
     * x -> the game board to init
     */
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            board[i][j] = '-';
        }
    }
}

void board_show(char board[3][3], int y, int x, int cursor[2])
{
    /*
     * x -> the game board to show
     */
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (i == cursor[0] && j == cursor[1]) 
                attron(A_REVERSE);
            mvprintw(y + 2*i, x + 3*j,"%c", board[i][j]);
            attroff(A_REVERSE);
        }
    }
    refresh();
}

void board_update(char board[3][3], int pos[2], char value)
{
    /*
     * x -> the game board to show
     * pos -> [row, column]
     */
    board[pos[0]][pos[1]] = value;
}

int board_check(char board[3][3], char symbol)
{
    /*
     * inputs:
     *      board -> game board
     *      symbol -> player symbol
     */
    int i;
    if (diags_check(board, symbol))
        return 1;

    for(i=0; i<3; i++){
        if(row_check(board, symbol, i) || col_check(board, symbol, i))
            return 1;
    }
    return 0;
}

int board_filled(char board[3][3], char symbol)
{
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j] == symbol)
                return 0;
        }
    }
    return 1;
}
        

int row_check(char board[3][3], char symbol, int row)
{
    int col, count;
    count = 0;
    for(col=0; col<3; col++){
        if (board[row][col] == symbol)
            count++;
    }
    if (count == 3)
        return 1;
    return 0;
}

int col_check(char board[3][3], char symbol, int col)
{
    int row, count;
    count = 0;
    for(row=0; row<3; row++){
        if (board[row][col] == symbol)
            count++;
    }
    if (count == 3)
        return 1;
    return 0;
}

int diags_check(char board[3][3], char symbol)
{
    int i, count, count1;
    count = count1 = 0;

    for(i=0; i<3; i++){
        if(board[i][i] == symbol)
            count++;
        if(board[i][2-i] == symbol)
            count1++;
    }
    if (count==3 || count1==3)
        return 1;
    return 0;
}
