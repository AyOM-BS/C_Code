#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void game ()
{
    int answer = 0;
    srand ((int) time(NULL));
    answer = 1 + rand() % 100;
    printf("请输入数字：\n");
    int guess = 0;
    time_t start = time(NULL);
    int count = 5;
    while (count)
    {
        scanf ("%d",&guess);
        if (guess < answer)
            printf("猜小了\n");
        else if (guess > answer)
            printf("猜大了\n");
        else
            {
                time_t end = time (NULL);
                printf("恭喜你，猜对了\n");
                printf("共用时%d秒\n",end - start);
                break;
            }
        count--;
    }
    if (count == 0)
        {
            printf("很遗憾，你输了\n");
            printf("答案是%d\n",answer);
        }
}

int main ()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int num = 0;
    do
    {
    printf("请选择：\n");
    printf("----------------\n");
    printf("-----1.开始-----\n");
    printf("-----2.结束-----\n");
    printf("----------------\n");
    scanf("%d",&num);
    if (num == 1)
    {
        printf("游戏开始\n");
        game ();
    }
    else if (num == 2)
        {
            printf("已退出\n");
            break;
        }
    else
        printf("输入错误，请选择1或2\n");
    }while (num != 2);
    return 0;
}