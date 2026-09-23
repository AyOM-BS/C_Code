#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "function.h"

void boardplay (char (*p)[4])
{
    for (int r = 0; r < 4; r++)
    {
        *(*(p)+r) = r + '0';
    }
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            *(*(p+i)+j) = '#';
        }
        *(*(p+i)) = i + '0';
    }
}

void display (char (*p)[4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c ",*(*(p+i)+j));
        }
        printf("\n");
    }
}

int judge (char (*p)[4])
{
    for (int i = 1; i < 4; i++)// 列判断
    {
        if(*(*(p+1)+i) == *(*(p+2)+i) && *(*(p+2)+i) == *(*(p+3)+i) && *(*(p+1)+i) != '#')
        {
            return 1;
        }
    }
    for (int i = 1; i < 4; i++)// 行判断
    {
        if(*(*(p+i)+1) == *(*(p+i)+2) && *(*(p+i)+2) == *(*(p+i)+3) && *(*(p+i)+1) != '#')
        {
            return 1;
        }
    }
    // 对角线判断
    if(*(*(p+1)+1) == *(*(p+2)+2) && *(*(p+2)+2) == *(*(p+3)+3) && *(*(p+1)+1) != '#')
    {
        return 1;
    }
    if(*(*(p+1)+3) == *(*(p+2)+2) && *(*(p+2)+2) == *(*(p+3)+1) && *(*(p+3)+1) != '#')
    {
        return 1;
    }
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4 ; j++)
        {
            if (*(*(p+i)+j) == '#')// 未结束
            {
                return 0;
            }
        }
    }
    // 平局
    return 2;
}

int player1(char (*p)[4])
{
    int x,y;
    while (1)
    {
        int r = scanf("%d%d",&x,&y);
        if (r == 2 && getchar() == '\n')
        {
            if (x > 0 && x < 4 && y > 0 && y < 4)
            {
            if (*(*(p+x)+y) == '#')
                {
                    *(*(p+x)+y) = '+';
                    system("cls");
                    display(p);
                    int judge_result = judge(p);
                    if (judge_result == 1)
                    {
                        return 1;
                    }
                    else if (judge_result == 2)
                    {
                        return 0;
                    }
                    else
                    {
                        return 3;
                    }
                }
                else
                {
                    printf("该坐标已被占用，请player1重新输入\n");
                }
            }
            else
            {
                printf("该位置非法，请player1重新输入\n");
            }
        }
        else
        {
            printf("该位置非法，请player1重新输入\n");
            while (getchar() != '\n')
            {}
        }
    }
}

int player2 (char (*p)[4])
{
    int x,y;
    while (1)
    {
        int r = scanf("%d%d",&x,&y);
        if (r == 2 && getchar() == '\n')
        {
            if (x > 0 && x < 4 && y > 0 && y < 4)
            {
                if (*(*(p+x)+y) == '#')
                {
                    *(*(p+x)+y) = '-';
                    system("cls");
                    display(p);
                    int judge_result = judge(p);
                    if (judge_result == 1)
                    {
                        return 2;
                    }
                    else if (judge_result == 2)
                    {
                        return 0;
                    }
                    else
                    {
                       return 3;
                    }
                }
                else
                {
                    printf("该坐标已被占用，请player2重新输入\n");
                }
            }
            else
            {
                printf("该位置非法，请player2重新输入\n");
            }
        }
        else
        {
            printf("该位置非法，请player2重新输入\n");
            while (getchar() != '\n')
            {}
        }
    }
}

void start(char (*p)[4])
{
    while(1)
    {
        printf("player1请选择位置\n");
        int result1 = player1 (p);
        if (result1 == 1)
        {
            printf ("player1 win.\n");
            break;
        }
        else if (result1 == 0)
        {
            printf ("diamond cut diamond.\n");
            break;
        }
        else
        {
            ;
        }
        printf("player2请选择位置\n");
        int result2 = player2 (p);
        if (result2 == 2)
        {
            printf ("player2 win.\n");
            break;
        }
        else if (result2 == 0)
        {
            printf ("diamond cut diamond.\n");
            break;
        }
        else
        {
            ;
        }
    }
    printf("\n");
    Sleep(3000);
    system("cls");
}

void game ()
{
    char play[4][4];
    boardplay(play);
    display(play);
    start(play);
}

void menu()
{
    int opt = 0;
    do
    {
        printf("请选择：\n");
        printf("----------------\n");
        printf("-----1.开始-----\n");
        printf("-----0.结束-----\n");
        printf("----------------\n");
        int r = scanf("%d",&opt);
        if (r == 1 && getchar() == '\n')
        // 防止输入1.1，只读取了1就进行下一步，而不判断输入是否合法
        {
            if (opt == 1)
            {
                printf("游戏开始......\n");
                Sleep(1000);
                system("cls");
                game ();
            }
                else if (opt == 0)
            {
                printf("已退出\n");
                break;
            }
            else
            {
                printf("输入错误，请选择1或0\n");
                Sleep(1000);
                system("cls");
                while (getchar() != '\n')
                {}
                // 每次输入完数据要按下回车，会产生一个\n
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
    }while (opt);
}
