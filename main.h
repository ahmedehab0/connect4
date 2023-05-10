#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

typedef struct{
	char sympol;
	void (*movefunc)(char board[BOARD_SIZE][BOARD_SIZE]);
} player;

typedef struct {
	player player1;
	player player2;
} HUMAN_GAME;

typedef struct {
	player player1;
	player player2;
} COMPUTER_GAME;

//FUNCTIONS

void (*menu())();
void init_board();
void print_board();
int is_game_over();
void human_move();
void rand_move();
char get_winner();
void human_game(HUMAN_GAME game);
void computer_game(COMPUTER_GAME game);

#endif

