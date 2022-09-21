#include "atd.h"
#include <string>
#include <stdio.h>
#include <iostream>

//конструктор класса employee со всеми параметрами
employee::employee(int i, experience e, hours h, jobtitle j) {
	id = i;
	exp = e;
	hour = h;
	jt = j;
}

//конструктор класса employee с одним параметром
employee::employee(int x) {
	id = x;
	experience e(x);
	hours h(x);
	jobtitle j(x);
	exp = e;
	hour = h;
	jt = j;
}

//конструктор класса employee без параметров
employee::employee() {
	id = 0;
	experience e;
	hours h;
	jobtitle j;
	exp = e;
	hour = h;
	jt = j;
}

//метод полного вывода employee
void employee::output() {
	cout << "ID: " << this->id << endl;
	exp.output();
	hour.output();
	jt.output();
}

//метод ввода employee
void employee::input() {
	cout << "Введите ID: ";
	cin >> this->id;
	exp.input();
	hour.input();
	while (getchar() != '\n');
	jt.input();
}

//метод подсчета зарплаты
int employee::getsalary(int overtimecost, int weekendscost, int exppercent, \
	int expstatus, int subspercent, int subsstatus) {
	int salary = 0; //зарплата
	float experience = exp.workingyears + exp.army + exp.maternityleave;
	salary += hour.normal * jt.hourlycost;
	salary += hour.overtime * overtimecost;
	salary += hour.weekends * weekendscost;
	//учет стажа
	if (expstatus == true)
		salary += salary / 100 * exppercent * experience;
	else
		salary += salary / 100 * exppercent * exp.workingyears;
	//учет наличия подчиненных
	if (jt.subs.amount && subsstatus)
		salary += jt.subs.amount * salary / 100 * subspercent / jt.subs.asos;
	else
		salary += jt.subs.amount * salary / 100 * subspercent;
	return salary;
}

//метод подсчета премии (положена или нет)
int employee::getpremium(int houramount) {
	/*if (this->hour.getnormal() + this->hour.getovertime() + this->hour.getweekends() < houramount)
		return 0;
	else*/
		return 1;
}