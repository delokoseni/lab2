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

//����� ������
void experience::output() {
	cout << "���� (���������� ���): " << workingyears << endl;
	cout << "���� (���-�� ��� � �����): " << army << endl;
	cout << "���� (���-�� ��� � ��������� �������): " << maternityleave << endl;
}

//����� ���������� ������� ����� � ����������� ����
float experience::monthstodecimal(int years, float month) {
	float exp;
	exp = years + month / 12;
	return exp;
};