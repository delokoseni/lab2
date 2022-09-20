#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "experience.h"

//функция ввода структуры experience
Experience inputexp() {
	Experience exp;
	int army;
	float workingyears, maternityleave;
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
	exp.army = army;
	exp.maternityleave = maternityleave;
	exp.workingyears = workingyears;
	return exp;
}

Experience expinitiation(float workingyears, int army, float maternityleave) {
	Experience exp;
	exp.workingyears = workingyears;
	exp.army = army;
	exp.maternityleave = maternityleave;
	return exp;
}