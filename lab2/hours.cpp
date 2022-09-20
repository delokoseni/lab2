#include "hours.h"
#include <iostream>
using namespace std;

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

//����� ����� ������ hours
void hours::input() {
	cout << "������� ���-�� ������������ �� ����� �����(�����): ";
	cin >> normal;
	cout << "������� ���-�� ������������ �����: ";
	cin >> overtime;
	cout << "������� ���-�� ������������ �� ����� ����� � ��������: ";
	cin >> weekends;
}
