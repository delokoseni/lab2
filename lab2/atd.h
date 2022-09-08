#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>

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
Employee initiation(int id, int workingyears, int army, int maternityleave,
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
	printf("Введите ID: ");
	scanf("%d", &(human.id));
	printf("Введите общий стаж (кол-во лет): ");
	scanf("%d", &(human.exp.workingyears));
	printf("Из них в армии (кол-во лет): ");
	scanf("%d", &(human.exp.army));
	printf("Из них в декретном отпуске (кол-во лет): ");
	scanf("%d", &(human.exp.maternityleave));
	if (human.exp.army > 0)
		human.exp.workingyears -= human.exp.army;
	if (human.exp.maternityleave > 0)
		human.exp.workingyears -= human.exp.maternityleave;
	printf("Введите кол-во отработанных за месяц часов: ");
	scanf("%d", &(human.hour.normal));
	printf("Введите кол-во сверхурочных часов : ");
	scanf("%d", &(human.hour.overtime));
	printf("Введите кол-во отработанных за месяц часов в выходные: ");
	scanf("%d", &(human.hour.weekends));
	if (human.hour.overtime > 0)
		human.hour.normal -= human.hour.overtime;
	if (human.hour.weekends > 0)
		human.hour.normal -= human.hour.weekends;
	printf("Введите должность: ");
	scanf("%s", human.jt.jtitle);
	printf("Введите стоимость часа работы: ");
	scanf("%d", &(human.jt.hourlycost));
	printf("Введите количество подчиненных сотрудника: ");
	scanf("%d", &(human.jt.subs.amount));
	if (human.jt.subs.amount > 0) {
		printf("Введите средний стаж подчиненных сотрудника: ");
		scanf("%f", &(human.jt.subs.ASoS));
	}
	return human;
}

//функция полного вывода
void output(Employee human) {
	printf("ID: %d\n", human.id);
	printf("Стаж (отработано лет): %d\n", human.exp.workingyears);
	printf("Стаж (кол-во лет в армии): %d\n", human.exp.army);
	printf("Стаж (кол-во лет в декретном отпуске): %d\n", human.exp.maternityleave);
	printf("Отработано часов за месяц(по графику): %d\n", human.hour.normal);
	printf("Отработано часов за месяц(сверхурочно): %d\n", human.hour.overtime);
	printf("Отработано часов за месяц(в выходные дни): %d\n", human.hour.weekends);
	printf("Должность: %s\n", human.jt.jtitle);
	printf("Стоимость часа работы: %s\n", human.jt.hourlycost);
	printf("Кол-во подчиненных: %s\n", human.jt.subs.amount);
	printf("Средний стаж подчиненных: %s\n", human.jt.subs.ASoS);
}

//функция короткого вывода
void shortoutput(Employee human) {
	printf("ID: %d\n", human.id);
	printf("Стаж: %d\n", human.exp.workingyears + human.exp.army + human.exp.maternityleave);
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