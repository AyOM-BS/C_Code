#ifndef FUNCTION_H
#define FUNCTION_H

#define ROWS 18
#define COLS 32

// 只是声明，变量定义放在function.c，防止多文件重复定义,导致不可生成exe文件
extern int ROW,COL,LEI;

void boardlei(char lei[ROWS][COLS], char set1);
void boardplay(char play[ROWS][COLS], char set2);
void display1(char play[ROWS][COLS]);
void display2(char lei[ROWS][COLS]);
void replace(char lei[ROWS][COLS]);
int NUM(char lei[ROWS][COLS],int x,int y);
void findplay0(char play[ROWS][COLS],char lei[ROWS][COLS],int x,int y,int* p);
void find(char play[ROWS][COLS],char lei[ROWS][COLS]);
void game ();
void MENU();

#endif