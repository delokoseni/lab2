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
	experience();
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

//конструктор класса experience без параметров
experience::experience() {
	workingyears = 0;
	army = 0;
	maternityleave = 0;
}

//АТД отработанные за месяц часы
class hours {
public:
	hours(int n, int o, int w);
	hours();
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

//конструктор класса hours без параметров
hours::hours() {
	normal = 0;
	overtime = 0;
	weekends = 0;
}

//АТД подчиненные
class subordinates {
public:
	subordinates(int a, float A);
	subordinates();
private:
	int amount; //кол-во подчиненных
	float ASoS; //average seniority of subordinates - средний стаж подчиненных
};

//конструктор класса subordinates со всеми параметрами
subordinates::subordinates(int a, float A) {
	amount = a;
	ASoS = A;
}

//конструктор класса subordinates без параметров
subordinates::subordinates() {
	amount = 0;
	ASoS = 0;
}

//АТД должность
class jobtitle {
public:
	jobtitle(string j, int h, subordinates s);
	jobtitle();
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

//конструктор класса jobtitle без параметров
jobtitle::jobtitle() {
	jtitle = "";
	hourlycost = 0;
	subordinates subs;
}

//АТД Сотрудник
class employee {
public:
	employee(int i, experience e, hours h, jobtitle j);
	employee();
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

//конструктор класса employee без параметров
employee::employee() {
	id = 0;
	experience exp;
	hours hour;
	jobtitle jt;
}