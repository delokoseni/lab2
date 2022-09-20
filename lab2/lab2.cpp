#include "atd.h"
#include <conio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size, i;
    char c;
    employee human1, *men[3];
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
        cout << "Введите размер массива: ";
        cin >> size;
        employee* arr = new employee[size]; //динамический массив объектов класса
        for (i = 0; i < size; i++) {
            (arr + i)->input();
            (arr + i)->output();
            cout << "Премия: " << (*arr).getpremium(140) << endl;
        }
        delete[] arr;
        employee* human = new employee;
        *human = human1;
        human1.output();
        (*human).output();
        delete human;
        //работа с массивом динамических объектов класса
        men[0] = &human1;
        men[1] = &human2;
        men[2] = &human3;
        for (i = 0; i < 3; i++) {
            men[i]->output();
        }
        printf("Для повтора программы нажмите любую клавишу.\n");
        printf("Для выхода из программы нажмите ESC.\n");
        c = _getch();
    } while (c != 27);
    return 0;
}