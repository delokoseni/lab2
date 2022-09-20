#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "subordinates.h"

//функци€ ввода структуры subordinates
Subordinates inputsubs() {
	Subordinates subs;
	int amount;
	float asos;
	printf("¬ведите количество подчиненных сотрудника: ");
	scanf("%d", &amount);
	if (amount > 0) {
		printf("¬ведите средний стаж подчиненных сотрудника: ");
		scanf("%f", &asos);
	}
	else
		asos = 0;
	subs.amount = amount;
	subs.asos = asos;
	return subs;
}

//функци€ инициализации
Subordinates subsinitiation(int amount, float asos) {
	Subordinates subs;
	subs.amount = amount;
	subs.asos = asos;
	return subs;
}