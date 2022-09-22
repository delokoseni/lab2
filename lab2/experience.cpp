#include "experience.h"
#include <iostream>
using namespace std;

//конструктор класса experience со всеми параметрами
experience::experience(int w, int a, int m) {
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
	cout << "¬ведите общий стаж (кол-во лет): ";
	cin >> workingyears;
	cout << "»з них в армии (кол-во лет): ";
	cin >> army;
	cout << "»з них в декретном отпуске(кол - во лет) :";
	cin >> maternityleave;
	workingyears = workingyears - army - maternityleave;
}

//метод вывода
void experience::output() {
	cout << "—таж (отработано лет): " << workingyears << endl;
	cout << "—таж (кол-во лет в армии): " << army << endl;
	cout << "—таж (кол-во лет в декретном отпуске): " << maternityleave << endl;
}

//метод возвращающий совокупный стаж
float experience::monthstodecimal() {
	int exp;
	exp = workingyears + army + maternityleave;
	return exp;
};