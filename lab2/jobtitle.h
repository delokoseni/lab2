#pragma once
#include "subordinates.h"
#include <string>
using namespace std;

class jobtitle
{
public:
	jobtitle(string j, int h, subordinates s);
	jobtitle(int x);
	jobtitle();
	string getjtitle();
	int gethourlycost();
	subordinates getsubs();
	void input();
private:
	string jtitle; //������������ ���������
	int hourlycost; //��������� ���� ������
	subordinates subs; //�����������
};

