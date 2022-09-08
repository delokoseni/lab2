#include "atd.h"
#include <conio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Employee human1;
    char c, str[30] = "Менеджер";
    do{
        human1 = initiation(117, 5, 0, 0, 36, 4, 0, str, 140, 0, 0);
        output(human1);
        human1 = input();
        shortoutput(human1);
        printf("Для повтора программы нажмите любую клавишу.\n");
        printf("Для выхода из программы нажмите ESC.\n");
        c = _getch();
    } while (c != 27);
    return 0;
}