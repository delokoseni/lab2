#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>

//��� ����
typedef struct experience {
	float workingyears; //���-�� ������� ������������ ���
	int army; //���-�� ��� � �����, ���� ����������� ������� �����
	float maternityleave; //���-�� ��� � ��������� �������, ���� ����������� ������� �����
}Experience;

//��� ������������ �� ����� ����
typedef struct hours {
	int normal; //���-�� �����, ������������ �� �������
	int overtime; //���-�� �����, ������������ �����������
	int weekends; //��� - �� �����, ������������ � �������� ���
}Hours;

//��� �����������
typedef struct subordinates {
	int amount; //���-�� �����������
	float ASoS; //average seniority of subordinates - ������� ���� �����������
}Subordinates;

//��� ���������
typedef struct jobtitle {
	char jtitle[30]; //������������ ���������
	int hourlycost; //��������� ���� ������
	Subordinates subs; //�����������
}Jobtitle;

//��� ���������
typedef struct employee {
	int id; //�������������� �����
	Experience exp; //����
	Hours hour; //������������ �� ����� ����
	Jobtitle jt; //���������
	
} Employee;

//������� �������������
Employee initiation(int id, float workingyears, int army, float maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, float ASoS) {
	Employee human;
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
	human.jt.subs.ASoS = ASoS;
	return human;
}
//������� �����
Employee input() {
	Employee human;
	int id, army, normal, overtime, weekends, hourlycost, amount;
	float ASoS, workingyears, maternityleave;
	char jtitle[30];
	printf("������� ID: ");
	scanf("%d", &id);
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
	printf("������� ���-�� ������������ �� ����� �����: ");
	scanf("%d", &(normal));
	printf("������� ���-�� ������������ ����� : ");
	scanf("%d", &(overtime));
	printf("������� ���-�� ������������ �� ����� ����� � ��������: ");
	scanf("%d", &(weekends));
	if (overtime > 0)
		normal -= overtime;
	if (weekends > 0)
		normal -= weekends;
	printf("������� ���������: ");
	scanf("%s", jtitle);
	printf("������� ��������� ���� ������: ");
	scanf("%d", &hourlycost);
	printf("������� ���������� ����������� ����������: ");
	scanf("%d", &amount);
	if (amount > 0) {
		printf("������� ������� ���� ����������� ����������: ");
		scanf("%f", &ASoS);
	}
	else
		ASoS = 0;
	human = initiation(id, workingyears, army, maternityleave, normal, overtime, \
		weekends, jtitle, hourlycost, amount, ASoS);
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
	printf("������� ���� �����������: %.1f\n", human.jt.subs.ASoS);
}

//������� ��������� ������
void shortoutput(Employee human) {
	printf("ID: %d\n", human.id);
	printf("����: %.1f\n", human.exp.workingyears + human.exp.army + human.exp.maternityleave);
	printf("���������� ����� �� �����: %d\n", human.hour.normal + human.hour.overtime + human.hour.weekends);
	printf("���������: %s\n", human.jt.jtitle);
}

//������� �������� ��������
int Salary(Employee human) {
	int salary = 0; //��������
	return salary;
}

//������� �������� ������
int Premium(Employee human) {
	int premium = 0; //������
	return premium;
}