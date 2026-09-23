#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "function.h"

int ROW,COL,LEI;

void boardlei(char lei[ROWS][COLS], char set1)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            lei[i][j] = set1;
        }
    }
}

void boardplay(char play[ROWS][COLS], char set2)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            play[i][j] = set2;
        }
    }
}

void display1(char play[ROWS][COLS])
{
    if (COL < 10)
    {
        for (int a = 0; a <= COL; a++)
        {
            printf ("%d  ",a);
        }
        printf ("\n");
    }
    else
    {
        for (int a = 0; a < 10; a++)
        {
            printf ("%d  ",a);
        }
        for (int a = 10; a <= COL; a++)
        {
            printf ("%d ",a);
        }
        printf ("\n");
    }
    printf ("\n");
    for (int i = 1; i <= 9; i++)
    {
        printf ("%d  ",i);
        for (int j = 1; j <= COL; j++)
        {
            printf ("%c  ",play[i][j]);
        }
        printf ("\n");
        printf ("\n");
    }
    for (int i = 10; i <= ROW; i++)
    {
        printf ("%d ",i);
        for (int j = 1; j <= COL; j++)
        {
            printf ("%c  ",play[i][j]);
        }
        printf ("\n");
        printf ("\n");
    }
}

void display2(char lei[ROWS][COLS])
{
    if (COL < 10)
    {
        for (int a = 0; a <= COL; a++)
        {
            printf ("%d  ",a);
        }
        printf ("\n");
    }
    else
    {
        for (int a = 0; a < 10; a++)
        {
            printf ("%d  ",a);
        }
        for (int a = 10; a <= COL; a++)
        {
            printf ("%d ",a);
        }
        printf ("\n");
    }
    printf ("\n");
    for (int i = 1; i <= 9; i++)
    {
        printf ("%d  ",i);
        for (int j = 1; j <= COL; j++)
        {
            printf ("%c  ",lei[i][j]);
        }
        printf ("\n");
        printf ("\n");
    }
    for (int i = 10; i <= ROW; i++)
    {
        printf ("%d ",i);
        for (int j = 1; j <= COL; j++)
        {
            printf ("%c  ",lei[i][j]);
        }
        printf ("\n");
        printf ("\n");
    }
}

void replace(char lei[ROWS][COLS])
{
    for (int count = LEI; count; count--)
    {
        int i = rand() % ROW + 1;
        int j = rand() % COL + 1;
        if (lei[i][j] == '1')
        {
            count ++;
            continue;
        }
        else
        {
            lei[i][j] = '1';
        }
    }
}

int NUM(char lei[ROWS][COLS],int x,int y)
{
    return (lei[x-1][y-1] + lei[x-1][y] + lei [x-1][y+1] + lei[x][y-1] + lei[x][y+1] + lei[x+1][y-1] + lei[x+1][y] + lei[x+1][y+1] - 8*'0');
}

void findplay0(char play[ROWS][COLS],char lei[ROWS][COLS],int x,int y,int* p)
{
    if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))
    {
        if (play[x][y] != '#')// 防止被检查过的格子被重复查找
        {
            return;
        }
        play[x][y] = NUM(lei,x,y) + '0';
        (*p)++;// 注意是(*p)++不是p++
        if (NUM(lei,x,y) == 0)
        {
            for (int i = -1; i <= 1; i++)
            {
            for (int j = -1; j <= 1; j++)
                {
                    if (i == 0 && j == 0)// 跳过自己
                    {
                        continue;
                    }
                    findplay0(play,lei,x+i,y+j,p);
                }
            }
        }
        else
        {
        }
    }
}

void find(char play[ROWS][COLS],char lei[ROWS][COLS])
{
    time_t time_start = time(NULL);
    int x = 0;
    int y = 0;
    int choose = 0;
    int win = 0;
    while (win < (ROW*COL - LEI))
    {
        printf("请选择：1.排雷 2.插/拔旗\n");
        scanf("%d",&choose);
        if(choose == 1)
        {
            printf("请输入你要查找的坐标(x y)\n");
            scanf("%d%d",&x,&y);
            if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))
            {
                if (play[x][y] != '#')
                {
                    printf("该坐标已被查找，请重新输入\n");
                }
                else
                {
                    if (lei[x][y] == '1')
                    {
                        printf("踩到雷了，已结束\n");
                        Sleep(1000);
                        system("cls");
                        display2(lei);
                        Sleep(3000);
                        system("cls");
                        break;
                    }
                    else
                    {
                        findplay0(play,lei,x,y,&win);
                        system("cls");
                        display1(play);
                    }
                }
            }
            else
            {
                printf("请重新输入坐标\n");
            }
        }
        else if(choose == 2)
        {
            printf("请输入你要插/拔旗的坐标(x y)\n");
            scanf("%d%d",&x,&y);
            if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))
            {
                if (play[x][y] == '#')
                {
                    play[x][y] = '?';
                }
                else if (play[x][y] == '?')
                {
                    play[x][y] = '#';
                }
                else
                {
                    printf("该坐标不可插/拔旗\n");
                }
            }
            else
            {
                printf("请重新输入坐标\n");
            }
            system("cls");
            display1(play);
        }
        else
        {
            printf("请重新输入\n");
        }
    }
    if (win == (ROW*COL - LEI))
    {
        printf("你赢了\n");
        system("cls");
        display2(lei);
        time_t time_end = time(NULL);
        printf("共用时%d秒\n",time_end - time_start);
        Sleep(3000);
        system("cls");
    }
}

void game ()
{
    char lei[ROWS][COLS];// 存储雷
    char play[ROWS][COLS];// 存储游戏过程
    //防止越界，对9*9棋盘扩展为11*11大小
    boardlei(lei, '0');// 雷面板
    boardplay(play, '#');// 游戏面板
    replace(lei);// 布雷
    Sleep(1000);
    system("cls");
    display1(play);// 展示游戏面板
    // display2(lei);// 展示雷的位置
    find(play,lei);// 游戏过程
}

void MENU()
{
    int opt = 0;
    do
    {
        printf ("请选择：\n");
        printf ("----------------\n");
        printf ("-----1.简单-----\n");// 9*9 10
        printf ("-----2.普通-----\n");// 16*16 40
        printf ("-----3.困难-----\n");// 16*30 99
        printf ("-----0.退出-----\n");
        printf ("----------------\n");
        int r = scanf ("%d",&opt);
        if(r == 1 && getchar() == '\n')
        {
            if (opt == 1)
            {
                printf ("游戏开始.......\n");
                ROW = 9;
                COL = 9;
                LEI = 10;
                game ();
            }
            else if (opt == 2)
            {
                printf ("游戏开始.......\n");
                ROW = 16;
                COL = 16;
                LEI = 40;
                game ();
            }
            else if (opt == 3)
            {
                printf ("游戏开始.......\n");
                ROW = 16;
                COL = 30;
                LEI = 99;
                game ();
            }
            else if (opt == 0)
            {
                break;
            }
            else
            {
                printf ("请在1和0之间选择\n");
            }
        }
        else
        {
            printf("输入错误，请选择1或0\n");
            Sleep(1000);
            system("cls");
            while (getchar() != '\n')
            {}
        }
    } while (opt);
}