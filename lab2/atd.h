#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

//АТД стаж
class experience {
public:
	experience(float w, int a, float m);
	experience(int x);
	experience();
	float getworkingyears();
	int getarmy();
	float getmaternityleave();
	void set(float w, int a, float m);
private:
	float workingyears; //кол-во реально отработанных лет
	int army; //кол-во лет в армии, если сохранялось рабочее место
	float maternityleave; //кол-во лет в декретном отпуске, если сохранялось рабочее место
};

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

//методы получения данных из класса experience
float experience::getworkingyears() {
	return this->workingyears;
}

int experience::getarmy() {
	return this->army;
}

float experience::getmaternityleave() {
	return this->maternityleave;
}

//метод установки значений в классе experience
void experience::set(float w, int a, float m) {
	workingyears = w;
	army = a;
	maternityleave = m;
}

//АТД отработанные за месяц часы
class hours {
public:
	hours(int n, int o, int w);
	hours(int x);
	hours();
	int getnormal();
	int getovertime();
	int getweekends();
	void set(int n, int o, int w);
private:
	int normal; //кол-во часов, отработанных по графику
	int overtime; //кол-во часов, отработанных сверхурочно
	int weekends; //кол - во часов, отработанных в выходные дни
};

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

//метод установки значений в классе hours
void hours::set(int n , int o, int w) {
	normal = n;
	overtime = o;
	weekends = w;
}

//АТД подчиненные
class subordinates {
public:
	subordinates(int a, float A);
	subordinates(int x);
	subordinates();
	int getamount();
	float getasos();
	void set(int a, float A);
private:
	int amount; //кол-во подчиненных
	float asos; //average seniority of subordinates - средний стаж подчиненных
};

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

//методы получения данных из класса subordinates
int subordinates::getamount() {
	return this->amount;
}

float subordinates::getasos() {
	return this->asos;
}

//метод установки значений в классе subordinates
void subordinates::set(int a, float A) {
	amount = a;
	asos = A;
}

//АТД должность
class jobtitle {
public:
	jobtitle(string j, int h, subordinates s);
	jobtitle(int x);
	jobtitle();
	string getjtitle();
	int gethourlycost();
	subordinates getsubs();
	void set(string j, int h, subordinates s);
private:
	string jtitle; //наименование должности
	int hourlycost; //стоимость часа работы
	subordinates subs; //подчиненные
};

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

//методы получения данных из класса jobtitle
string jobtitle::getjtitle() {
	return this->jtitle;
}

int jobtitle::gethourlycost() {
	return this->hourlycost;
}

subordinates jobtitle::getsubs() {
	return this->subs;
}

void jobtitle::set(string j, int h, subordinates s) {
	jtitle = j;
	hourlycost = h;
	subs = s;
}

//АТД Сотрудник
class employee {
public:
	employee(int i, experience e, hours h, jobtitle j);
	employee(int x);
	employee();
	void output();
	void shortoutput();
	void input();
	int getsalary(int overtimecost, int weekendscost, int exppercent, \
		int expstatus, int subspercent, int subsstatus);
	int getpremium(int houramount);
private:
	int id; //индивидуальный номер
	experience exp; //стаж
	hours hour; //отработанные за месяц часы
	jobtitle jt; //должность
};

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
	subordinates s = this->jt.getsubs();
	cout << "ID: " << this->id << endl;
	cout << "Стаж (отработано лет): " << this->exp.getworkingyears() << endl;
	cout << "Стаж (кол-во лет в армии): " << this->exp.getarmy() << endl;
	cout << "Стаж (кол-во лет в декретном отпуске): " << this->exp.getmaternityleave() << endl;
	cout << "Отработано часов за месяц(по графику): " << this->hour.getnormal() << endl;
	cout << "Отработано часов за месяц(сверхурочно): " << this->hour.getovertime() << endl;
	cout << "Отработано часов за месяц(в выходные дни): " << this->hour.getweekends() << endl;
	cout << "Должность: " << this->jt.getjtitle() << endl;
	cout << "Стоимость часа работы: " << this->jt.gethourlycost() << endl;
	cout << "Кол-во подчиненных: " << s.getamount() << endl;
	cout << "Средний стаж подчиненных: " << s.getasos() << endl << endl;
}

//метод короткого вывода employee
void employee::shortoutput() {
	cout << "ID: " << this->id << endl;
	cout << "Стаж: " << this->exp.getworkingyears() \
		+ this->exp.getarmy() + this->exp.getmaternityleave() << endl;
	cout << "Отработано часов за месяц: " << this->hour.getnormal() \
		+ this->hour.getovertime() + this->hour.getweekends() << endl;
	cout << "Должность: "<< this->jt.getjtitle() << endl << endl;
}

//метод ввода employee
void employee::input() {
	experience exp;
	hours hour;
	jobtitle jt;
	subordinates subs;
	int army, normal, overtime, weekends, hourlycost, amount, asos = 0;
	float workingyears, maternityleave;
	string jtitle;
	cout << "Введите ID: ";
	cin >> this->id;
	cout << "Введите общий стаж (кол-во лет): ";
	cin >> workingyears;
	cout << "Из них в армии (кол-во лет): ";
	cin >> army;
	cout << "Из них в декретном отпуске(кол - во лет) :";
	cin >> maternityleave;
	exp.set(workingyears - army - maternityleave, army, maternityleave);
	this->exp = exp;
	cout << "Введите кол-во отработанных за месяц часов(всего): ";
	cin >> normal;
	cout << "Введите кол-во сверхурочных часов: ";
	cin >> overtime;
	cout << "Введите кол-во отработанных за месяц часов в выходные: ";
	cin >> weekends;
	hour.set(normal - overtime - weekends, overtime, weekends);
	this->hour = hour;
	while (getchar() != '\n');
	cout << "Введите должность: ";
	getline(cin, jtitle);
	cout << "Введите стоимость часа работы: ";
	cin >> hourlycost;
	cout << "Введите количество подчиненных сотрудника: ";
	cin >> amount;
	if (amount > 0) {
		cout << "Введите средний стаж подчиненных сотрудника: ";
		cin >> asos;
	}
	subs.set(amount, asos);
	jt.set(jtitle, hourlycost, subs);
	this->jt = jt;
}

//метод подсчета зарплаты
int employee::getsalary(int overtimecost, int weekendscost, int exppercent, \
	int expstatus, int subspercent, int subsstatus) {
	int salary = 0; //зарплата
	float experience = this->exp.getworkingyears() + this->exp.getarmy() + this->exp.getmaternityleave();
	salary += this->hour.getnormal() * this->jt.gethourlycost();
	salary += this->hour.getovertime() * overtimecost;
	salary += this->hour.getweekends() * weekendscost;
	subordinates subs;
	//учет стажа
	if (expstatus == true)
		salary += salary / 100 * exppercent * experience;
	else
		salary += salary / 100 * exppercent * this->exp.getworkingyears();
	//учет наличия подчиненных
	subs = this->jt.getsubs();
	if (subs.getamount() && subsstatus)
		salary += subs.getamount() * salary / 100 * subspercent / subs.getasos();
	else
		salary += subs.getamount() * salary / 100 * subspercent;
	return salary;
}

//метод подсчета премии (положена или нет)
int employee::getpremium(int houramount) {
	if(this->hour.getnormal() + this->hour.getovertime() + this->hour.getweekends() < houramount)
		return 0;
	else
		return 1;
}