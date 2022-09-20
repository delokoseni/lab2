#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "hours.h"

//������� ����� ��������� hours
Hours inputhour() {
	Hours hour;
	int normal, overtime, weekends;
	printf("������� ���-�� ������������ �� ����� �����: ");
	scanf("%d", &normal);
	printf("������� ���-�� ������������ ����� : ");
	scanf("%d", &overtime);
	printf("������� ���-�� ������������ �� ����� ����� � ��������: ");
	scanf("%d", &weekends);
	if (overtime > 0)
		normal -= overtime;
	if (weekends > 0)
		normal -= weekends;
	hour.normal = normal;
	hour.overtime = overtime;
	hour.weekends = weekends;
	return hour;
}


//������� ������
Hours hourinitiation(int normal, int overtime, int weekends) {
	Hours hour;
	hour.normal = normal;
	hour.overtime = overtime;
	hour.weekends = weekends;
	return hour;
}

void houroutput(Hours hour) {
	printf("���������� ����� �� �����(�� �������): %d\n", hour.normal);
	printf("���������� ����� �� �����(�����������): %d\n", hour.overtime);
	printf("���������� ����� �� �����(� �������� ���): %d\n", hour.weekends);
}