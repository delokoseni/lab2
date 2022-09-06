#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>

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
	int ASoS; //average seniority of subordinates - ������� ���� �����������
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

//#define _CRT_SECURE_NO_WARNINGS

//������� �������������
Employee initiation(int id, int workingyears, int army, int maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, int ASoS) {
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
void input(Employee human) {

}

//������� ������
void output(Employee human) {

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