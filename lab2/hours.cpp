#include "hours.h"
#include <iostream>
using namespace std;

//конструктор класса hours со всеми параметрами
hours::hours(int n, int o, int w) {
	normal = n;
	overtime = o;
	weekends = w;
}

//конструктор класса hours с одним параметром
hours::hours(int x) {
	normal = x;
	overtime = x;
	weekends = x;
}

//конструктор класса hours без параметров
hours::hours() {
	normal = 0;
	overtime = 0;
	weekends = 0;
}

//методы получения данных из класса hours
int hours::getnormal() {
	return this->normal;
}
int hours::getovertime() {
	return this->overtime;
}
int hours::getweekends() {
	return this->weekends;
}

//метод ввода класса hours
void hours::input() {
	cout << "Введите кол-во отработанных за месяц часов(всего): ";
	cin >> normal;
	cout << "Введите кол-во сверхурочных часов: ";
	cin >> overtime;
	cout << "Введите кол-во отработанных за месяц часов в выходные: ";
	cin >> weekends;
}
