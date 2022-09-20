#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "experience.h"
#include "hours.h"
#include "subordinates.h"
#include "jobtitle.h"
#include "atd.h"

Subordinates inputsubs();
Jobtitle inputjt();
Hours inputhour();
Experience inputexp();

//������� �������������
Employee initiation(int id, float workingyears, int army, float maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, float ASoS) {
	Employee human;
	human.jt.jtitle = (char*)malloc(sizeof(char));
	human.id = id;
	human.exp.workingyears = workingyears;
	human.exp.army = army;
	human.exp.maternityleave = maternityleave;
	human.hour.normal = normal;
	human.hour.overtime = overtime;
	human.hour.weekends = weekends;
	strcpy(human.jt.jtitle, jtitle);
	human.jt.hourlycost = hourlycost;
	human.jt.subs.amount = amount;
	human.jt.subs.asos = ASoS;
	return human;
}

//������� ����� employee
Employee input() {
	Employee human;
	int id;
	printf("������� ID: ");
	scanf("%d", &id);
	human.id = id;
	human.exp = inputexp();
	human.hour = inputhour();
	while (getchar() != '\n');
	human.jt = inputjt();
	return human;
}

//������� ������� ������
void output(Employee human) {
	printf("ID: %d\n", human.id);
	printf("���� (���������� ���): %.1f\n", human.exp.workingyears);
	printf("���� (���-�� ��� � �����): %d\n", human.exp.army);
	printf("���� (���-�� ��� � ��������� �������): %.1f\n", human.exp.maternityleave);
	printf("���������� ����� �� �����(�� �������): %d\n", human.hour.normal);
	printf("���������� ����� �� �����(�����������): %d\n", human.hour.overtime);
	printf("���������� ����� �� �����(� �������� ���): %d\n", human.hour.weekends);
	printf("���������: %s\n", human.jt.jtitle);
	printf("��������� ���� ������: %d\n", human.jt.hourlycost);
	printf("���-�� �����������: %d\n", human.jt.subs.amount);
	printf("������� ���� �����������: %.1f\n", human.jt.subs.asos);
}

//������� ��������� ������
void shortoutput(Employee human) {
	printf("ID: %d\n", human.id);
	printf("����: %.1f\n", human.exp.workingyears + human.exp.army + human.exp.maternityleave);
	printf("���������� ����� �� �����: %d\n", human.hour.normal + human.hour.overtime + human.hour.weekends);
	printf("���������: %s\n", human.jt.jtitle);
}

//������� �������� ��������
int getsalary(Employee human, int overtimecost, int weekendscost, int exppercent, \
	int expstatus, int subspercent, int subsstatus) {
	int salary = 0; //��������
	float experience = human.exp.workingyears + human.exp.army + human.exp.maternityleave;
	salary += human.hour.normal * human.jt.hourlycost;
	salary += human.hour.overtime * overtimecost;
	salary += human.hour.weekends * weekendscost;
	//���� �����
	if (expstatus == true)
		salary += salary / 100 * exppercent * experience;
	else
		salary += salary / 100 * exppercent * human.exp.workingyears;
	//���� ������� �����������
	if (human.jt.subs.amount && subsstatus)
		salary += human.jt.subs.amount * salary / 100 * subspercent / human.jt.subs.asos;
	else
		salary += human.jt.subs.amount * salary / 100 * subspercent;
	return salary;
}

//������� �������� ������ (�������� ��� ���)
int getpremium(Employee human, int houramount) {
	if (human.hour.normal + human.hour.overtime + human.hour.weekends < houramount)
		return 0;
	else
		return 1;
}