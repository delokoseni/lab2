#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "experience.h"

//������� ����� ��������� experience
Experience inputexp() {
	Experience exp;
	int army;
	float workingyears, maternityleave;
	printf("������� ����� ���� (���-�� ���): ");
	scanf("%f", &workingyears);
	printf("�� ��� � ����� (���-�� ���): ");
	scanf("%d", &army);
	printf("�� ��� � ��������� ������� (���-�� ���): ");
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