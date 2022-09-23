#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "experience.h"

//функция ввода структуры experience
Experience inputexp() {
	Experience exp;
	int army, workingyears, maternityleave;
	printf("Введите общий стаж (кол-во лет): ");
	scanf("%d", &workingyears);
	printf("Из них в армии (кол-во лет): ");
	scanf("%d", &army);
	printf("Из них в декретном отпуске (кол-во лет): ");
	scanf("%d", &maternityleave);
	if (army > 0)
		workingyears -= army;
	if (maternityleave > 0)
		workingyears -= maternityleave;
	exp.army = army;
	exp.maternityleave = maternityleave;
	exp.workingyears = workingyears;
	return exp;
}

//функция инициализации
Experience expinitiation(int workingyears, int army, int maternityleave) {
	Experience exp;
	exp.workingyears = workingyears;
	exp.army = army;
	exp.maternityleave = maternityleave;
	return exp;
}

//функция вывода
void expoutput(Experience exp) {
	printf("Стаж (отработано лет): %d\n", exp.workingyears);
	printf("Стаж (кол-во лет в армии): %d\n", exp.army);
	printf("Стаж (кол-во лет в декретном отпуске): %d\n", exp.maternityleave);
}

//функция возвращающая общий стаж
int monthstodecimal(Experience exp) {
	int allexp;
	allexp = exp.workingyears;
	allexp += exp.army;
	allexp += exp.maternityleave;
	return allexp;
}