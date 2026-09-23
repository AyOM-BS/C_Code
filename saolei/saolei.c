#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "function.h"

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    srand ((int)time(NULL));
    MENU();
    return 0;
}