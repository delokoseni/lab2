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

//метод приведени€ мес€цев стажа к дес€тичному виду
float experience::monthstodecimal(int years, float month) {
	float exp;
	exp = years + month / 12;
	return exp;
};