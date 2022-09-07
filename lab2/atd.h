#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>

//��� ����
typedef struct experience {
	int workingyears; //���-�� ������� ������������ ���
	int army; //���-�� ��� � �����, ���� ����������� ������� �����
	int maternityleave; //���-�� ��� � ��������� �������, ���� ����������� ������� �����
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
	Hours h; //������������ �� ����� ����
	Jobtitle jt; //���������
	
} Employee;

//������� �������������
Employee initiation(int id, int workingyears, int army, int maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, float ASoS) {
	Employee human;
	human.id = id;
	human.exp.workingyears = workingyears;
	human.exp.army = army;
	human.exp.maternityleave = maternityleave;
	human.h.normal = normal;
	human.h.overtime = overtime;
	human.h.weekends = weekends;
	strcpy(human.jt.jtitle, jtitle);
	human.jt.hourlycost = hourlycost;
	human.jt.subs.amount = amount;
	human.jt.subs.ASoS = ASoS;
	return human;
}
//������� �����
Employee input() {
	Employee human;
	printf("������� ID: ");
	scanf("%d", &(human.id));
	printf("������� ����� ���� (���-�� ���): ");
	scanf("%d", &(human.exp.workingyears));
	printf("�� ��� � ����� (���-�� ���): ");
	scanf("%d", &(human.exp.army));
	printf("�� ��� � ��������� ������� (���-�� ���): ");
	scanf("%d", &(human.exp.maternityleave));
	if (human.exp.army > 0)
		human.exp.workingyears -= human.exp.army;
	if (human.exp.maternityleave > 0)
		human.exp.workingyears -= human.exp.maternityleave;
	printf("������� ���-�� ������������ �� ����� �����: ");
	scanf("%d", &(human.h.normal));
	printf("������� ���-�� ������������ ����� : ");
	scanf("%d", &(human.h.overtime));
	printf("������� ���-�� ������������ �� ����� ����� � ��������: ");
	scanf("%d", &(human.h.weekends));
	if (human.h.overtime > 0)
		human.h.normal -= human.h.overtime;
	if (human.h.weekends > 0)
		human.h.normal -= human.h.weekends;
	printf("������� ���������: ");
	scanf("%s", human.jt.jtitle);
	printf("������� ��������� ���� ������: ");
	scanf("%d", &(human.jt.hourlycost));
	printf("������� ���������� ����������� ����������: ");
	scanf("%d", &(human.jt.subs.amount));
	if (human.jt.subs.amount > 0) {
		printf("������� ������� ���� ����������� ����������: ");
		scanf("%f", &(human.jt.subs.ASoS));
	}
	return human;
}

//������� ������
void output(Employee human) {
	printf("ID: %d\n", human.id);
	printf("����: %d\n", human.exp.workingyears + human.exp.army + human.exp.maternityleave);
	printf("���������� ����� �� �����: %d\n", human.h.normal + human.h.overtime + human.h.weekends);
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