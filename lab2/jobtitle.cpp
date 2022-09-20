#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "jobtitle.h"
#include "jobtitle.h"

Subordinates inputsubs();
Subordinates subsinitiation(int amount, float asos);

//функци€ ввода структуры jobtitle
Jobtitle inputjt() {
	Jobtitle jt;
	int hourlycost;
	long lenghtofjtitle = 1; //длина jtitle + 1
	char* jtitle, c;
	jtitle = (char*)malloc(sizeof(char));
	printf("¬ведите должность: ");
	while ((c = getchar()) != '\n') {
		jtitle[lenghtofjtitle - 1] = c;
		lenghtofjtitle++;
		jtitle = (char*)realloc(jtitle, lenghtofjtitle);
	}
	jtitle[lenghtofjtitle - 1] = '\0';
	printf("¬ведите стоимость часа работы: ");
	scanf("%d", &hourlycost);
	jt.hourlycost = hourlycost;
	jt.jtitle = jtitle;
	jt.subs = inputsubs();
	return jt;
}

//функци€ инициализации
Jobtitle jtinitiation(char jtitle[], int hourlycost, int amount, float asos) {
	Jobtitle jt;
	jt.jtitle = (char*)malloc(sizeof(char));
	jt.subs = subsinitiation(amount, asos);
	strcpy(jt.jtitle, jtitle);
	jt.hourlycost = hourlycost;
	return jt;
}