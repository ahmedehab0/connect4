#ifndef MAIN_H
#define MAIN_H

//FUNCTIONS

void menu();
void init_board();
void print_board();
void human_move(player player);
void rand_move(player player);
char get_winner();
void animate_move();
void play_1player_game(player human_player, player computer_player);
void play_2player_game(player player1, player player2);
#endif

