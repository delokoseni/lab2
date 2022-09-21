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

//метод ввода класса hours
void hours::input() {
	cout << "¬ведите кол-во отработанных за мес€ц часов(всего): ";
	cin >> normal;
	cout << "¬ведите кол-во сверхурочных часов: ";
	cin >> overtime;
	cout << "¬ведите кол-во отработанных за мес€ц часов в выходные: ";
	cin >> weekends;
}

//метод вывода
void hours::output() {
	cout << "ќтработано часов за мес€ц(по графику): " << normal << endl;
	cout << "ќтработано часов за мес€ц(сверхурочно): " << overtime << endl;
	cout << "ќтработано часов за мес€ц(в выходные дни): " << weekends << endl;
}

//метод получени€ отработанных за мес€ц часов
int hours::allhours() {
	int all = 0;
	all += normal;
	all += overtime;
	all += weekends;
	return all;
}