#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>

//АТД стаж
typedef struct experience {
	int workingyears; //кол-во реально отработанных лет
	int army; //кол-во лет в армии, если сохранялось рабочее место
	int maternityleave; //кол-во лет в декретном отпуске, если сохранялось рабочее место
}Experience;

//АТД отработанные за месяц часы
typedef struct hours {
	int normal; //кол-во часов, отработанных по графику
	int overtime; //кол-во часов, отработанных сверхурочно
	int weekends; //кол - во часов, отработанных в выходные дни
}Hours;

//АТД подчиненные
typedef struct subordinates {
	int amount; //кол-во подчиненных
	int ASoS; //average seniority of subordinates - средний стаж подчиненных
}Subordinates;

//АТД должность
typedef struct jobtitle {
	char jtitle[30]; //наименование должности
	int hourlycost; //стоимость часа работы
	Subordinates subs; //подчиненные
}Jobtitle;

//АТД Сотрудник
typedef struct employee {
	int id; //индивидуальный номер
	Experience exp; //стаж
	Hours h; //отработанные за месяц часы
	Jobtitle jt; //должность
	
} Employee;

//#define _CRT_SECURE_NO_WARNINGS

//функция инициализации
Employee initiation(int id, int workingyears, int army, int maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, int ASoS) {
	Employee human;
	human.id = id;
	human.exp.workingyears = workingyears;
	human.exp.army = army;
	human.exp.maternityleave = maternityleave;
	human.h.normal = normal;
	human.h.overtime = overtime;
	human.h.weekends = weekends;
	strcpy(human.jt.jtitle, jtitle);
	human.jt.hourlycost = hourlycost;
	human.jt.subs.amount = amount;
	human.jt.subs.ASoS = ASoS;
	return human;
}
//функция ввода
void input(Employee human) {

}

//функция вывода
void output(Employee human) {

}

//функция подсчета зарплаты
int Salary(Employee human) {
	int salary = 0; //зарплата
	return salary;
}

//функция подсчета премии
int Premium(Employee human) {
	int premium = 0; //премия
	return premium;
}