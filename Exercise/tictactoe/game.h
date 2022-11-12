#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3


void menu();
void init(char board[ROW][COL], int row, int col);
void game();
void print_board(char board[ROW][COL], int row, int col);
void player(char board[ROW][COL]);
int isrep(char board[ROW][COL], int x, int y);
int is_legal(char board[ROW][COL], int x, int y);
void cp(char board[ROW][COL]);
int is_win(char board[ROW][COL]);
int full(char board[ROW][COL]);
int win(char board[ROW][COL],char piece);