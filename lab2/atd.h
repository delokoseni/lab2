#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

//��� ����
class experience {
public:
	experience(float w, int a, float m);
	experience();
private:
	float workingyears; //���-�� ������� ������������ ���
	int army; //���-�� ��� � �����, ���� ����������� ������� �����
	float maternityleave; //���-�� ��� � ��������� �������, ���� ����������� ������� �����
};

//����������� ������ experience �� ����� �����������
experience::experience(float w, int a, float m) {
	workingyears = w;
	army = a;
	maternityleave = m;
}

//����������� ������ experience ��� ����������
experience::experience() {
	workingyears = 0;
	army = 0;
	maternityleave = 0;
}

//��� ������������ �� ����� ����
class hours {
public:
	hours(int n, int o, int w);
	hours();
private:
	int normal; //���-�� �����, ������������ �� �������
	int overtime; //���-�� �����, ������������ �����������
	int weekends; //��� - �� �����, ������������ � �������� ���
};

//����������� ������ hours �� ����� �����������
hours::hours(int n, int o, int w) {
	normal = n;
	overtime = o;
	weekends = w;
}

//����������� ������ hours ��� ����������
hours::hours() {
	normal = 0;
	overtime = 0;
	weekends = 0;
}

//��� �����������
class subordinates {
public:
	subordinates(int a, float A);
	subordinates();
private:
	int amount; //���-�� �����������
	float ASoS; //average seniority of subordinates - ������� ���� �����������
};

//����������� ������ subordinates �� ����� �����������
subordinates::subordinates(int a, float A) {
	amount = a;
	ASoS = A;
}

//����������� ������ subordinates ��� ����������
subordinates::subordinates() {
	amount = 0;
	ASoS = 0;
}

//��� ���������
class jobtitle {
public:
	jobtitle(string j, int h, subordinates s);
	jobtitle();
private:
	string jtitle; //������������ ���������
	int hourlycost; //��������� ���� ������
	subordinates subs; //�����������
};

//����������� ������ jobtitle �� ����� �����������
jobtitle::jobtitle(string j, int h, subordinates s) {
	jtitle = j;
	hourlycost = h;
	subs = s;
}

//����������� ������ jobtitle ��� ����������
jobtitle::jobtitle() {
	jtitle = "";
	hourlycost = 0;
	subordinates subs;
}

//��� ���������
class employee {
public:
	employee(int i, experience e, hours h, jobtitle j);
	employee();
private:
	int id; //�������������� �����
	experience exp; //����
	hours hour; //������������ �� ����� ����
	jobtitle jt; //���������
};

//����������� ������ employee �� ����� �����������
employee::employee(int i, experience e, hours h, jobtitle j) {
	id = i;
	exp = e;
	hour = h;
	jt = j;
}

//����������� ������ employee ��� ����������
employee::employee() {
	id = 0;
	experience exp;
	hours hour;
	jobtitle jt;
}