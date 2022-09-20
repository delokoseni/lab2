#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

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
	cout << "������� ID: ";
	cin >> this->id;
	exp.input();
	hour.input();
	while (getchar() != '\n');
	jt.input();
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