#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
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

//������� ������
void subsoutput(Subordinates subs) {
	printf("���-�� �����������: %d\n", subs.amount);
	printf("������� ���� �����������: %.1f\n", subs.asos);
}

//������� �������� �������� ���������� ������������ ���
float averageseniority(int number) {
	int i;
	float* arr = (float*)calloc(2 * number, sizeof(float));
	float avesen = 0;
	printf("������� ������� ����� ���, ����� ����� ������������ �������!");
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