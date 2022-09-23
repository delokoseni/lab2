#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "experience.h"

//������� ����� ��������� experience
Experience inputexp() {
	Experience exp;
	int army, workingyears, maternityleave;
	printf("������� ����� ���� (���-�� ���): ");
	scanf("%d", &workingyears);
	printf("�� ��� � ����� (���-�� ���): ");
	scanf("%d", &army);
	printf("�� ��� � ��������� ������� (���-�� ���): ");
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

//������� �������������
Experience expinitiation(int workingyears, int army, int maternityleave) {
	Experience exp;
	exp.workingyears = workingyears;
	exp.army = army;
	exp.maternityleave = maternityleave;
	return exp;
}

//������� ������
void expoutput(Experience exp) {
	printf("���� (���������� ���): %d\n", exp.workingyears);
	printf("���� (���-�� ��� � �����): %d\n", exp.army);
	printf("���� (���-�� ��� � ��������� �������): %d\n", exp.maternityleave);
}

//������� ������������ ����� ����
int monthstodecimal(Experience exp) {
	int allexp;
	allexp = exp.workingyears;
	allexp += exp.army;
	allexp += exp.maternityleave;
	return allexp;
}