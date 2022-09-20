#include "experience.h"
#include <iostream>
using namespace std;

//конструктор класса experience со всеми параметрами
experience::experience(float w, int a, float m) {
	workingyears = w;
	army = a;
	maternityleave = m;
}

//конструктор класса experience с одним параметром
experience::experience(int x) {
	workingyears = x;
	army = x;
	maternityleave = x;
}

//конструктор класса experience без параметров
experience::experience() {
	workingyears = 0;
	army = 0;
	maternityleave = 0;
}

//метод ввода класса experience
void experience::input() {
	cout << "Введите общий стаж (кол-во лет): ";
	cin >> workingyears;
	cout << "Из них в армии (кол-во лет): ";
	cin >> army;
	cout << "Из них в декретном отпуске(кол - во лет) :";
	cin >> maternityleave;
	workingyears = workingyears - army - maternityleave;
}

//метод вывода
void experience::output() {
	cout << "Стаж (отработано лет): " << workingyears << endl;
	cout << "Стаж (кол-во лет в армии): " << army << endl;
	cout << "Стаж (кол-во лет в декретном отпуске): " << maternityleave << endl;
}