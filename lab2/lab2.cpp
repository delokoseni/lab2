#include "atd.h"
#include <conio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size, i;
    char c;
    employee human1, *men[5];
    employee human2(2);
    experience exp(1);
    hours hour(1);
    jobtitle jt(1);
    employee human3(1, exp, hour, jt);
    do{
        human1.output();
        human2.output();
        human3.output();
        cout << "Зарплата: " << human3.getsalary(200, 220, 2, 1, 5, 1) << endl;
        cout << "Премия: " << human3.getpremium(200) << endl;
        human3.shortoutput();
        cout << "Введите размер массива: ";
        cin >> size;
        employee* arr = new employee[size];
        for (i = 0; i < size; i++) {
            (arr + i)->input();
            (arr + i)->shortoutput();
            cout << "Премия: " << (*arr).getpremium(140) << endl;
        }
        delete[] arr;
        employee* human = new employee;
        *human = human1;
        for (i = 0; i < 5; i++)
            men[i] = human;
        men[0]->output();
        delete human;
        printf("Для повтора программы нажмите любую клавишу.\n");
        printf("Для выхода из программы нажмите ESC.\n");
        c = _getch();
    } while (c != 27);
    return 0;
}