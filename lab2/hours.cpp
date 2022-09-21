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

//����� ����� ������ hours
void hours::input() {
	cout << "������� ���-�� ������������ �� ����� �����(�����): ";
	cin >> normal;
	cout << "������� ���-�� ������������ �����: ";
	cin >> overtime;
	cout << "������� ���-�� ������������ �� ����� ����� � ��������: ";
	cin >> weekends;
}

//����� ������
void hours::output() {
	cout << "���������� ����� �� �����(�� �������): " << normal << endl;
	cout << "���������� ����� �� �����(�����������): " << overtime << endl;
	cout << "���������� ����� �� �����(� �������� ���): " << weekends << endl;
}

//����� ��������� ������������ �� ����� �����
int hours::allhours() {
	int all = 0;
	all += normal;
	all += overtime;
	all += weekends;
	return all;
}