#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>

//АТД стаж
typedef struct experience {
	float workingyears; //кол-во реально отработанных лет
	int army; //кол-во лет в армии, если сохранялось рабочее место
	float maternityleave; //кол-во лет в декретном отпуске, если сохранялось рабочее место
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
	float ASoS; //average seniority of subordinates - средний стаж подчиненных
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
	Hours hour; //отработанные за месяц часы
	Jobtitle jt; //должность
	
} Employee;

//функция инициализации
Employee initiation(int id, float workingyears, int army, float maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, float ASoS) {
	Employee human;
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
	human.jt.subs.ASoS = ASoS;
	return human;
}
//функция ввода
Employee input() {
	Employee human;
	int id, army, normal, overtime, weekends, hourlycost, amount;
	float ASoS, workingyears, maternityleave;
	char jtitle[30];
	printf("Введите ID: ");
	scanf("%d", &id);
	printf("Введите общий стаж (кол-во лет): ");
	scanf("%f", &workingyears);
	printf("Из них в армии (кол-во лет): ");
	scanf("%d", &army);
	printf("Из них в декретном отпуске (кол-во лет): ");
	scanf("%f", &maternityleave);
	if (army > 0)
		workingyears -= army;
	if (maternityleave > 0)
		workingyears -= maternityleave;
	printf("Введите кол-во отработанных за месяц часов: ");
	scanf("%d", &(normal));
	printf("Введите кол-во сверхурочных часов : ");
	scanf("%d", &(overtime));
	printf("Введите кол-во отработанных за месяц часов в выходные: ");
	scanf("%d", &(weekends));
	if (overtime > 0)
		normal -= overtime;
	if (weekends > 0)
		normal -= weekends;
	printf("Введите должность: ");
	scanf("%s", jtitle);
	printf("Введите стоимость часа работы: ");
	scanf("%d", &hourlycost);
	printf("Введите количество подчиненных сотрудника: ");
	scanf("%d", &amount);
	if (amount > 0) {
		printf("Введите средний стаж подчиненных сотрудника: ");
		scanf("%f", &ASoS);
	}
	else
		ASoS = 0;
	human = initiation(id, workingyears, army, maternityleave, normal, overtime, \
		weekends, jtitle, hourlycost, amount, ASoS);
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
	printf("Средний стаж подчиненных: %.1f\n", human.jt.subs.ASoS);
}

//функция короткого вывода
void shortoutput(Employee human) {
	printf("ID: %d\n", human.id);
	printf("Стаж: %.1f\n", human.exp.workingyears + human.exp.army + human.exp.maternityleave);
	printf("Отработано часов за месяц: %d\n", human.hour.normal + human.hour.overtime + human.hour.weekends);
	printf("Должность: %s\n", human.jt.jtitle);
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