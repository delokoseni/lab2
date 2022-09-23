#include "atd.h"
#include "stdio.h"
#include <conio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Employee human1;
    char c, str[] = "Менеджер";
    do{
        human1 = initiation(117, 5, 0, 0, 36, 4, 0, str, 140, 0, 0);
        output(human1);
        human1 = input();
        output(human1);
        printf("Положена ли премия: %d\n", getpremium(human1, 140));
        printf("Зарплата: %d\n", getsalary(human1, 200, 210, 5, 1, 2, 1));
        printf("%f\n", averageseniority(4));
        printf("%d\n", allhours(human1.hour));
        printf("%f\n", comparisonhc(human1.jt, 100));
        printf("%d\n", monthstodecimal(human1.exp));
        printf("Для повтора программы нажмите любую клавишу.\n");
        printf("Для выхода из программы нажмите ESC.\n");
        c = _getch();
    } while (c != 27);
    return 0;
}