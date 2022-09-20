#include "jobtitle.h"
#include "subordinates.h"
#include <iostream>
#include <string>
using namespace std;

//конструктор класса jobtitle со всеми параметрами
jobtitle::jobtitle(string j, int h, subordinates s) {
	jtitle = j;
	hourlycost = h;
	subs = s;
}

//конструктор класса jobtitle с одним параметром
jobtitle::jobtitle(int x) {
	jtitle = to_string(x);
	hourlycost = x;
	subordinates s(x);
	subs = s;
}

//конструктор класса jobtitle без параметров
jobtitle::jobtitle() {
	jtitle = "";
	hourlycost = 0;
	subordinates s;
	subs = s;
}

//метод ввода класса jobtitle
void jobtitle::input() {
	cout << "¬ведите должность: ";
	getline(cin, jtitle);
	cout << "¬ведите стоимость часа работы: ";
	cin >> hourlycost;
	subs.input();
}

//метод вывода
void jobtitle::output() {
	cout << "ƒолжность: " << jtitle << endl;
	cout << "—тоимость часа работы: " << hourlycost << endl;
	subs.output();
}