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

//функция инициализации
Employee initiation(int id, float workingyears, int army, float maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, float ASoS) {
	Employee human;
	human.jt.jtitle = (char*)malloc(sizeof(char));
	human.id = id;
	human.exp.workingyears = workingyears;
	human.exp.army = army;
	human.exp.maternityleave = maternityleave;
	human.hour.normal = normal;
	human.hour.overtime = overtime;
	human.hour.weekends = weekends;
	strcpy(human.jt.jtitle, jtitle);
	human.jt.hourlycost = hourlycost;
	human.jt.subs.amount = amount;
	human.jt.subs.asos = ASoS;
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
	printf("Стаж (отработано лет): %.1f\n", human.exp.workingyears);
	printf("Стаж (кол-во лет в армии): %d\n", human.exp.army);
	printf("Стаж (кол-во лет в декретном отпуске): %.1f\n", human.exp.maternityleave);
	printf("Отработано часов за месяц(по графику): %d\n", human.hour.normal);
	printf("Отработано часов за месяц(сверхурочно): %d\n", human.hour.overtime);
	printf("Отработано часов за месяц(в выходные дни): %d\n", human.hour.weekends);
	printf("Должность: %s\n", human.jt.jtitle);
	printf("Стоимость часа работы: %d\n", human.jt.hourlycost);
	printf("Кол-во подчиненных: %d\n", human.jt.subs.amount);
	printf("Средний стаж подчиненных: %.1f\n", human.jt.subs.asos);
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