#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>

//ј“ƒ стаж
typedef struct experience {
	int workingyears; //кол-во реально отработанных лет
	int army; //кол-во лет в армии, если сохран€лось рабочее место
	int maternityleave; //кол-во лет в декретном отпуске, если сохран€лось рабочее место
}Experience;

//ј“ƒ отработанные за мес€ц часы
typedef struct hours {
	int normal; //кол-во часов, отработанных по графику
	int overtime; //кол-во часов, отработанных сверхурочно
	int weekends; //кол - во часов, отработанных в выходные дни
}Hours;

//ј“ƒ подчиненные
typedef struct subordinates {
	int amount; //кол-во подчиненных
	float ASoS; //average seniority of subordinates - средний стаж подчиненных
}Subordinates;

//ј“ƒ должность
typedef struct jobtitle {
	char jtitle[30]; //наименование должности
	int hourlycost; //стоимость часа работы
	Subordinates subs; //подчиненные
}Jobtitle;

//ј“ƒ —отрудник
typedef struct employee {
	int id; //индивидуальный номер
	Experience exp; //стаж
	Hours h; //отработанные за мес€ц часы
	Jobtitle jt; //должность
	
} Employee;

//функци€ инициализации
Employee initiation(int id, int workingyears, int army, int maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, float ASoS) {
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
//функци€ ввода
Employee input() {
	Employee human;
	printf("¬ведите ID: ");
	scanf("%d", &(human.id));
	printf("¬ведите общий стаж (кол-во лет): ");
	scanf("%d", &(human.exp.workingyears));
	printf("»з них в армии (кол-во лет): ");
	scanf("%d", &(human.exp.army));
	printf("»з них в декретном отпуске (кол-во лет): ");
	scanf("%d", &(human.exp.maternityleave));
	if (human.exp.army > 0)
		human.exp.workingyears -= human.exp.army;
	if (human.exp.maternityleave > 0)
		human.exp.workingyears -= human.exp.maternityleave;
	printf("¬ведите кол-во отработанных за мес€ц часов: ");
	scanf("%d", &(human.h.normal));
	printf("¬ведите кол-во сверхурочных часов : ");
	scanf("%d", &(human.h.overtime));
	printf("¬ведите кол-во отработанных за мес€ц часов в выходные: ");
	scanf("%d", &(human.h.weekends));
	if (human.h.overtime > 0)
		human.h.normal -= human.h.overtime;
	if (human.h.weekends > 0)
		human.h.normal -= human.h.weekends;
	printf("¬ведите должность: ");
	scanf("%s", human.jt.jtitle);
	printf("¬ведите стоимость часа работы: ");
	scanf("%d", &(human.jt.hourlycost));
	printf("¬ведите количество подчиненных сотрудника: ");
	scanf("%d", &(human.jt.subs.amount));
	if (human.jt.subs.amount > 0) {
		printf("¬ведите средний стаж подчиненных сотрудника: ");
		scanf("%f", &(human.jt.subs.ASoS));
	}
	return human;
}

//функци€ вывода
void output(Employee human) {
	printf("ID: %d\n", human.id);
	printf("—таж: %d\n", human.exp.workingyears + human.exp.army + human.exp.maternityleave);
	printf("ќтработано часов за мес€ц: %d\n", human.h.normal + human.h.overtime + human.h.weekends);
	printf("ƒолжность: %s\n", human.jt.jtitle);
}

//функци€ подсчета зарплаты
int Salary(Employee human) {
	int salary = 0; //зарплата
	return salary;
}

//функци€ подсчета премии
int Premium(Employee human) {
	int premium = 0; //преми€
	return premium;
}