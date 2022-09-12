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
	void set(float w, int a, float m);
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

//����� ��������� �������� � ������ experience
void experience::set(float w, int a, float m) {
	workingyears = w;
	army = a;
	maternityleave = m;
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
	void set(int n, int o, int w);
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

//����� ��������� �������� � ������ hours
void hours::set(int n , int o, int w) {
	normal = n;
	overtime = o;
	weekends = w;
}

//��� �����������
class subordinates {
public:
	subordinates(int a, float A);
	subordinates(int x);
	subordinates();
	int getamount();
	float getasos();
	void set(int a, float A);
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

//����� ��������� �������� � ������ subordinates
void subordinates::set(int a, float A) {
	amount = a;
	asos = A;
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
	void set(string j, int h, subordinates s);
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
	subordinates s(x);
	subs = s;
}

//����������� ������ jobtitle ��� ����������
jobtitle::jobtitle() {
	jtitle = "";
	hourlycost = 0;
	subordinates s;
	subs = s;
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

void jobtitle::set(string j, int h, subordinates s) {
	jtitle = j;
	hourlycost = h;
	subs = s;
}

//��� ���������
class employee {
public:
	employee(int i, experience e, hours h, jobtitle j);
	employee(int x);
	employee();
	void output();
	void shortoutput();
	void input();
	int getsalary(int overtimecost, int weekendscost, int exppercent, \
		int expstatus, int subspercent, int subsstatus);
	int getpremium(int houramount);
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
	experience e(x);
	hours h(x);
	jobtitle j(x);
	exp = e;
	hour = h;
	jt = j;
}

//����������� ������ employee ��� ����������
employee::employee() {
	id = 0;
	experience e;
	hours h;
	jobtitle j;
	exp = e;
	hour = h;
	jt = j;
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

//����� ����� employee
void employee::input() {
	experience exp;
	hours hour;
	jobtitle jt;
	subordinates subs;
	int army, normal, overtime, weekends, hourlycost, amount, asos = 0;
	float workingyears, maternityleave;
	string jtitle;
	cout << "������� ID: ";
	cin >> this->id;
	cout << "������� ����� ���� (���-�� ���): ";
	cin >> workingyears;
	cout << "�� ��� � ����� (���-�� ���): ";
	cin >> army;
	cout << "�� ��� � ��������� �������(��� - �� ���) :";
	cin >> maternityleave;
	exp.set(workingyears - army - maternityleave, army, maternityleave);
	this->exp = exp;
	cout << "������� ���-�� ������������ �� ����� �����(�����): ";
	cin >> normal;
	cout << "������� ���-�� ������������ �����: ";
	cin >> overtime;
	cout << "������� ���-�� ������������ �� ����� ����� � ��������: ";
	cin >> weekends;
	hour.set(normal - overtime - weekends, overtime, weekends);
	this->hour = hour;
	while (getchar() != '\n');
	cout << "������� ���������: ";
	getline(cin, jtitle);
	cout << "������� ��������� ���� ������: ";
	cin >> hourlycost;
	cout << "������� ���������� ����������� ����������: ";
	cin >> amount;
	if (amount > 0) {
		cout << "������� ������� ���� ����������� ����������: ";
		cin >> asos;
	}
	subs.set(amount, asos);
	jt.set(jtitle, hourlycost, subs);
	this->jt = jt;
}

//����� �������� ��������
int employee::getsalary(int overtimecost, int weekendscost, int exppercent, \
	int expstatus, int subspercent, int subsstatus) {
	int salary = 0; //��������
	float experience = this->exp.getworkingyears() + this->exp.getarmy() + this->exp.getmaternityleave();
	salary += this->hour.getnormal() * this->jt.gethourlycost();
	salary += this->hour.getovertime() * overtimecost;
	salary += this->hour.getweekends() * weekendscost;
	subordinates subs;
	//���� �����
	if (expstatus == true)
		salary += salary / 100 * exppercent * experience;
	else
		salary += salary / 100 * exppercent * this->exp.getworkingyears();
	//���� ������� �����������
	subs = this->jt.getsubs();
	if (subs.getamount() && subsstatus)
		salary += subs.getamount() * salary / 100 * subspercent / subs.getasos();
	else
		salary += subs.getamount() * salary / 100 * subspercent;
	return salary;
}

//����� �������� ������ (�������� ��� ���)
int employee::getpremium(int houramount) {
	if(this->hour.getnormal() + this->hour.getovertime() + this->hour.getweekends() < houramount)
		return 0;
	else
		return 1;
}