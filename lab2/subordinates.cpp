#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "subordinates.h"

//функция ввода структуры subordinates
Subordinates inputsubs() {
	Subordinates subs;
	int amount;
	float asos;
	printf("Введите количество подчиненных сотрудника: ");
	scanf("%d", &amount);
	if (amount > 0) {
		printf("Введите средний стаж подчиненных сотрудника: ");
		scanf("%f", &asos);
	}
	else
		asos = 0;
	subs.amount = amount;
	subs.asos = asos;
	return subs;
}

//функция инициализации
Subordinates subsinitiation(int amount, float asos) {
	Subordinates subs;
	subs.amount = amount;
	subs.asos = asos;
	return subs;
}

//функция вывода
void subsoutput(Subordinates subs) {
	printf("Кол-во подчиненных: %d\n", subs.amount);
	printf("Средний стаж подчиненных: %.1f\n", subs.asos);
}