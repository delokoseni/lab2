#pragma once
#include "subordinates.h"
#include <string>
using namespace std;

class jobtitle
{
	friend class employee;
public:
	jobtitle(string j, int h, subordinates s);
	jobtitle(int x);
	jobtitle();
	void input();
	void output();
	float comparisonhc(float hcost);
private:
	string jtitle; //������������ ���������
	int hourlycost; //��������� ���� ������
	subordinates subs; //�����������
};

