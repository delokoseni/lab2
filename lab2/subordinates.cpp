#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
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

//функция подсчета среднего количества отработанных лет
float averageseniority(int number) {
	int i;
	float* arr = (float*)calloc(2 * number, sizeof(float));
	float avesen = 0;
	printf("Вводите сначала число лет, затем число отработанных месяцев!");
	for (i = 0; i < 2 * number; i += 2) {
		scanf("%f", arr + i);
		scanf("%f", arr + i + 1);
	}
	for (i = 0; i < 2 * number; i += 2) {
		avesen += *(arr + i) + *(arr + i + 1) / 12;
	}
	avesen = avesen / number;
	return avesen;
}