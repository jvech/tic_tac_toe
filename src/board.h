
// Variables
void board_show(char (*)[3]);
void board_update(char (*)[3], int *, char);
void board_init(char (*)[3]);
int board_check(char (*)[3], char);
int board_filled(char (*)[3], char);

int row_check(char (*)[3], char, int);
int col_check(char (*)[3], char, int);
int diags_check(char (*)[3], char symbol);
