#include "experience.h"
#include <iostream>
using namespace std;

//����������� ������ experience �� ����� �����������
experience::experience(float w, int a, float m) {
	workingyears = w;
	army = a;
	maternityleave = m;
}

//����������� ������ experience � ����� ����������
experience::experience(int x) {
	workingyears = x;
	army = x;
	maternityleave = x;
}

//����������� ������ experience ��� ����������
experience::experience() {
	workingyears = 0;
	army = 0;
	maternityleave = 0;
}

//������ ��������� ������ �� ������ experience
float experience::getworkingyears() {
	return this->workingyears;
}

int experience::getarmy() {
	return this->army;
}

float experience::getmaternityleave() {
	return this->maternityleave;
}

//����� ����� ������ experience
void experience::input() {
	cout << "������� ����� ���� (���-�� ���): ";
	cin >> workingyears;
	cout << "�� ��� � ����� (���-�� ���): ";
	cin >> army;
	cout << "�� ��� � ��������� �������(��� - �� ���) :";
	cin >> maternityleave;
	workingyears = workingyears - army - maternityleave;
}
