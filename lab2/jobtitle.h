#pragma once
#include "subordinates.h"

//��� ���������
typedef struct jobtitle {
	char* jtitle; //������������ ���������
	int hourlycost; //��������� ���� ������
	Subordinates subs; //�����������
}Jobtitle;
