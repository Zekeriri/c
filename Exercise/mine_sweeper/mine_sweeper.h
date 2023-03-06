#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 10
#define COL 10
#define NUMS 10

void print_board(int board[ROW + 2][COL + 2],int row,int col);
void initialize_board(int board[ROW + 2][COL + 2], int row, int col);
void print_game_board(int board[ROW + 2][COL + 2], int game_board[ROW + 2][COL + 2], int row, int col);