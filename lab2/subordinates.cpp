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
	cout << "¬ведите количество подчиненных сотрудника: ";
	cin >> amount;
	if (amount > 0) {
		cout << "¬ведите средний стаж подчиненных сотрудника: ";
		cin >> asos;
	}
	else
		asos = 0;
}

//метод вывода
void subordinates::output() {
	cout << " ол-во подчиненных: " << amount << endl;
	cout << "—редний стаж подчиненных: " << asos << endl << endl;
}

//метод подсчета среднего стажа
float subordinates::averageseniority(int number) {
	float *arr = new float[2 *number];
	int i;
	float avesen = 0;
	cout << "¬водите сначала целое число лет стажа, затем мес€цы!" << endl;
	for (i = 0; i < 2 * number; i++) {
		cin >> *(arr + i);
	}
	for (i = 0; i < 2 * number; i+=2) {
		avesen += *(arr + i);
		avesen += *(arr + i + 1) / 12;
	}
	avesen = avesen / number;
	return avesen;
}