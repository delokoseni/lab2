#include "atd.h"
#include <conio.h>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size, i;
    float avesen;
    employee human1, *men[3];
    employee human2(2);
    experience exp(1);
    hours hour(1);
    jobtitle jt(1);
    jobtitle jj(200);
    employee human3(1, exp, hour, jt);
    subordinates s;
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
    avesen = s.averageseniority(4);
    avesen = jj.comparisonhc(180);
    cout << avesen << endl;
    //работа с массивом динамических объектов класса
    men[0] = &human1;
    men[1] = &human2;
    men[2] = &human3;
    for (i = 0; i < 3; i++) {
        men[i]->output();
    }
    return 0;
}