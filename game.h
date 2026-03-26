#ifndef GAME_H
#define GAME_H

void initialize_board(int x[4][4]);
void add_random_tile(int x[4][4]);
int move_left(int x[4][4]);
int move_right(int x[4][4]);
int move_up(int x[4][4]);
int move_down(int x[4][4]);
int is_game_over(int x[4][4]);
int score(int x[4][4]);

#endif
