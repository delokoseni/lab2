#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "subordinates.h"

//������� ����� ��������� subordinates
Subordinates inputsubs() {
	Subordinates subs;
	int amount;
	float asos;
	printf("������� ���������� ����������� ����������: ");
	scanf("%d", &amount);
	if (amount > 0) {
		printf("������� ������� ���� ����������� ����������: ");
		scanf("%f", &asos);
	}
	else
		asos = 0;
	subs.amount = amount;
	subs.asos = asos;
	return subs;
}

//������� �������������
Subordinates subsinitiation(int amount, float asos) {
	Subordinates subs;
	subs.amount = amount;
	subs.asos = asos;
	return subs;
}