#include "atd.h"
#include <conio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    employee human1();
    employee human2(1);
    subordinates people(1, 1);
    char c;
    string str = "Менеджер";
    jobtitle man(str, 140, people);
    do{
        
        printf("Для повтора программы нажмите любую клавишу.\n");
        printf("Для выхода из программы нажмите ESC.\n");
        c = _getch();
    } while (c != 27);
    return 0;
}