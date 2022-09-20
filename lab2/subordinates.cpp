#include "subordinates.h"
#include <iostream>
using namespace std;


//конструктор класса subordinates со всеми параметрами
subordinates::subordinates(int a, float A) {
	amount = a;
	asos = A;
}

//конструктор класса subordinates с одним параметром
subordinates::subordinates(int x) {
	amount = x;
	asos = x;
}

//конструктор класса subordinates без параметров
subordinates::subordinates() {
	amount = 0;
	asos = 0;
}

//метод ввода класса subordinates
void subordinates::input() {
	cout << "Введите количество подчиненных сотрудника: ";
	cin >> amount;
	if (amount > 0) {
		cout << "Введите средний стаж подчиненных сотрудника: ";
		cin >> asos;
	}
	else
		asos = 0;
}

//метод вывода
void subordinates::output() {
	cout << "Кол-во подчиненных: " << amount << endl;
	cout << "Средний стаж подчиненных: " << asos << endl << endl;
}