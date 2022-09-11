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
	experience(int x);
	experience();
	float getworkingyears();
	int getarmy();
	float getmaternityleave();
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

//����������� ������ experience � ����� ����������
experience::experience(int x) {
	workingyears = x;
	army = x;
	maternityleave = x;
}

//����������� ������ experience ��� ����������
experience::experience() {
	workingyears = 0;
	army = 0;
	maternityleave = 0;
}

//������ ��������� ������ �� ������ experience
float experience::getworkingyears() {
	return this->workingyears;
}

int experience::getarmy() {
	return this->army;
}

float experience::getmaternityleave() {
	return this->maternityleave;
}

//��� ������������ �� ����� ����
class hours {
public:
	hours(int n, int o, int w);
	hours(int x);
	hours();
	int getnormal();
	int getovertime();
	int getweekends();
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

//����������� ������ hours � ����� ����������
hours::hours(int x) {
	normal = x;
	overtime = x;
	weekends = x;
}

//����������� ������ hours ��� ����������
hours::hours() {
	normal = 0;
	overtime = 0;
	weekends = 0;
}

//������ ��������� ������ �� ������ hours
int hours::getnormal() {
	return this->normal;
}
int hours::getovertime() {
	return this->overtime;
}
int hours::getweekends() {
	return this->weekends;
}

//��� �����������
class subordinates {
public:
	subordinates(int a, float A);
	subordinates(int x);
	subordinates();
	int getamount();
	float getasos();
private:
	int amount; //���-�� �����������
	float asos; //average seniority of subordinates - ������� ���� �����������
};

//����������� ������ subordinates �� ����� �����������
subordinates::subordinates(int a, float A) {
	amount = a;
	asos = A;
}

//����������� ������ subordinates � ����� ����������
subordinates::subordinates(int x) {
	amount = x;
	asos = x;
}

//����������� ������ subordinates ��� ����������
subordinates::subordinates() {
	amount = 0;
	asos = 0;
}

//������ ��������� ������ �� ������ subordinates
int subordinates::getamount() {
	return this->amount;
}

float subordinates::getasos() {
	return this->asos;
}

//��� ���������
class jobtitle {
public:
	jobtitle(string j, int h, subordinates s);
	jobtitle(int x);
	jobtitle();
	string getjtitle();
	int gethourlycost();
	subordinates getsubs();
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

//����������� ������ jobtitle � ����� ����������
jobtitle::jobtitle(int x) {
	jtitle = to_string(x);
	hourlycost = x;
	subordinates subs(x);
}

//����������� ������ jobtitle ��� ����������
jobtitle::jobtitle() {
	jtitle = "";
	hourlycost = 0;
	subordinates subs;
}

//������ ��������� ������ �� ������ jobtitle
string jobtitle::getjtitle() {
	return this->jtitle;
}

int jobtitle::gethourlycost() {
	return this->hourlycost;
}

subordinates jobtitle::getsubs() {
	return this->subs;
}


//��� ���������
class employee {
public:
	employee(int i, experience e, hours h, jobtitle j);
	employee(int x);
	employee();
	void output();
	void shortoutput();
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

//����������� ������ employee � ����� ����������
employee::employee(int x) {
	id = x;
	experience exp(x);
	hours hour(x);
	jobtitle jt(x);
}

//����������� ������ employee ��� ����������
employee::employee() {
	id = 0;
	experience exp;
	hours hour;
	jobtitle jt;
}

//����� ������� ������ employee
void employee::output() {
	subordinates s = this->jt.getsubs();
	cout << "ID: " << this->id << endl;
	cout << "���� (���������� ���): " << this->exp.getworkingyears() << endl;
	cout << "���� (���-�� ��� � �����): " << this->exp.getarmy() << endl;
	cout << "���� (���-�� ��� � ��������� �������): " << this->exp.getmaternityleave() << endl;
	cout << "���������� ����� �� �����(�� �������): " << this->hour.getnormal() << endl;
	cout << "���������� ����� �� �����(�����������): " << this->hour.getovertime() << endl;
	cout << "���������� ����� �� �����(� �������� ���): " << this->hour.getweekends() << endl;
	cout << "���������: " << this->jt.getjtitle() << endl;
	cout << "��������� ���� ������: " << this->jt.gethourlycost() << endl;
	cout << "���-�� �����������: " << s.getamount() << endl;
	cout << "������� ���� �����������: " << s.getasos() << endl << endl;
}

//����� ��������� ������ employee
void employee::shortoutput() {
	cout << "ID: " << this->id << endl;
	cout << "����: " << this->exp.getworkingyears() \
		+ this->exp.getarmy() + this->exp.getmaternityleave() << endl;
	cout << "���������� ����� �� �����: " << this->hour.getnormal() \
		+ this->hour.getovertime() + this->hour.getweekends() << endl;
	cout << "���������: "<< this->jt.getjtitle() << endl << endl;
}