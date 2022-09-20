#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "experience.h"
#include "hours.h"
#include "subordinates.h"
#include "jobtitle.h"
#include "atd.h"

Subordinates inputsubs();
Jobtitle inputjt();
Hours inputhour();
Experience inputexp();
Experience expinitiation(float workingyears, int army, float maternityleave);
Hours hourinitiation(int normal, int overtime, int weekends);
Jobtitle jtinitiation(char jtitle[], int hourlycost, int amount, float asos);
void expoutput(Experience exp);
void houroutput(Hours hour);
void jtoutput(Jobtitle jt);

//функция инициализации
Employee initiation(int id, float workingyears, int army, float maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, float asos) {
	Employee human;
	human.id = id;
	human.exp = expinitiation(workingyears, army, maternityleave);
	human.hour = hourinitiation(normal, overtime, weekends);
	human.jt = jtinitiation(jtitle, hourlycost, amount, asos);
	return human;
}

//функция ввода employee
Employee input() {
	Employee human;
	int id;
	printf("Введите ID: ");
	scanf("%d", &id);
	human.id = id;
	human.exp = inputexp();
	human.hour = inputhour();
	while (getchar() != '\n');
	human.jt = inputjt();
	return human;
}

//функция полного вывода
void output(Employee human) {
	printf("ID: %d\n", human.id);
	expoutput(human.exp);
	houroutput(human.hour);
	jtoutput(human.jt);
}

//функция короткого вывода
void shortoutput(Employee human) {
	printf("ID: %d\n", human.id);
	printf("Стаж: %.1f\n", human.exp.workingyears + human.exp.army + human.exp.maternityleave);
	printf("Отработано часов за месяц: %d\n", human.hour.normal + human.hour.overtime + human.hour.weekends);
	printf("Должность: %s\n", human.jt.jtitle);
}

//функция подсчета зарплаты
int getsalary(Employee human, int overtimecost, int weekendscost, int exppercent, \
	int expstatus, int subspercent, int subsstatus) {
	int salary = 0; //зарплата
	float experience = human.exp.workingyears + human.exp.army + human.exp.maternityleave;
	salary += human.hour.normal * human.jt.hourlycost;
	salary += human.hour.overtime * overtimecost;
	salary += human.hour.weekends * weekendscost;
	//учет стажа
	if (expstatus == true)
		salary += salary / 100 * exppercent * experience;
	else
		salary += salary / 100 * exppercent * human.exp.workingyears;
	//учет наличия подчиненных
	if (human.jt.subs.amount && subsstatus)
		salary += human.jt.subs.amount * salary / 100 * subspercent / human.jt.subs.asos;
	else
		salary += human.jt.subs.amount * salary / 100 * subspercent;
	return salary;
}

//функция подсчета премии (положена или нет)
int getpremium(Employee human, int houramount) {
	if (human.hour.normal + human.hour.overtime + human.hour.weekends < houramount)
		return 0;
	else
		return 1;
}