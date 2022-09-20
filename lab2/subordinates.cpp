#include "subordinates.h"
#include <iostream>
using namespace std;


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

//����� ����� ������ subordinates
void subordinates::input() {
	cout << "������� ���������� ����������� ����������: ";
	cin >> amount;
	if (amount > 0) {
		cout << "������� ������� ���� ����������� ����������: ";
		cin >> asos;
	}
	else
		asos = 0;
}
