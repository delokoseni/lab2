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

//����� ������
void subordinates::output() {
	cout << "���-�� �����������: " << amount << endl;
	cout << "������� ���� �����������: " << asos << endl << endl;
}

//����� �������� �������� �����
float subordinates::averageseniority(int number) {
	float *arr = new float[2 *number];
	int i;
	float avesen = 0;
	cout << "������� ������� ����� ����� ��� �����, ����� ������!" << endl;
	for (i = 0; i < 2 * number; i++) {
		cin >> *(arr + i);
	}
	for (i = 0; i < 2 * number; i+=2) {
		avesen += *(arr + i);
		avesen += *(arr + i + 1) / 12;
	}
	avesen = avesen / number;
	return avesen;
}