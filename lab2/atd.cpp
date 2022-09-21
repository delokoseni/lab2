#include "atd.h"
#include <string>
#include <stdio.h>
#include <iostream>

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
	cout << "ID: " << this->id << endl;
	exp.output();
	hour.output();
	jt.output();
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
	float experience = exp.workingyears + exp.army + exp.maternityleave;
	salary += hour.normal * jt.hourlycost;
	salary += hour.overtime * overtimecost;
	salary += hour.weekends * weekendscost;
	//���� �����
	if (expstatus == true)
		salary += salary / 100 * exppercent * experience;
	else
		salary += salary / 100 * exppercent * exp.workingyears;
	//���� ������� �����������
	if (jt.subs.amount && subsstatus)
		salary += jt.subs.amount * salary / 100 * subspercent / jt.subs.asos;
	else
		salary += jt.subs.amount * salary / 100 * subspercent;
	return salary;
}

//����� �������� ������ (�������� ��� ���)
int employee::getpremium(int houramount) {
	/*if (this->hour.getnormal() + this->hour.getovertime() + this->hour.getweekends() < houramount)
		return 0;
	else*/
		return 1;
}