#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include "experience.h"
#include "hours.h"
#include "jobtitle.h"
#include "subordinates.h"
using namespace std;

//��� ���������
class employee {
public:
	employee(int i, experience e, hours h, jobtitle j);
	employee(int x);
	employee();
	void output();
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

