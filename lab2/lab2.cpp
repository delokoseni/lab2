#include "atd.h"
#include <conio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    employee human1;
    employee human2(1);
    subordinates people(1, 1);
    char c;
    string str = "Менеджер";
    jobtitle man(str, 140, people);
    experience exp(1);
    hours hour(1);
    jobtitle jt(1);
    employee human3(1, exp, hour, jt);
    cout << "Зарплата: " << human3.getsalary(200, 220, 2, 1, 5, 1) << endl;
    do{
        human2.output();
        human3.output();
        human3.shortoutput();
        human3.input();
        human3.output();
        printf("Для повтора программы нажмите любую клавишу.\n");
        printf("Для выхода из программы нажмите ESC.\n");
        c = _getch();
    } while (c != 27);
    return 0;
}