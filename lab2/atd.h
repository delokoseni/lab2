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

//АТД отработанные за месяц часы
class hours {
public:
	hours(int n, int o, int w);
	hours(int x);
	hours();
	int getnormal();
	int getovertime();
	int getweekends();
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

//АТД подчиненные
class subordinates {
public:
	subordinates(int a, float A);
	subordinates(int x);
	subordinates();
	int getamount();
	float getasos();
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

//АТД должность
class jobtitle {
public:
	jobtitle(string j, int h, subordinates s);
	jobtitle(int x);
	jobtitle();
	string getjtitle();
	int gethourlycost();
	subordinates getsubs();
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
	subordinates subs(x);
}

//конструктор класса jobtitle без параметров
jobtitle::jobtitle() {
	jtitle = "";
	hourlycost = 0;
	subordinates subs;
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


//АТД Сотрудник
class employee {
public:
	employee(int i, experience e, hours h, jobtitle j);
	employee(int x);
	employee();
	void output();
	void shortoutput();
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
	experience exp(x);
	hours hour(x);
	jobtitle jt(x);
}

//конструктор класса employee без параметров
employee::employee() {
	id = 0;
	experience exp;
	hours hour;
	jobtitle jt;
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