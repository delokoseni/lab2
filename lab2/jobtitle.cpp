#include "jobtitle.h"
#include "subordinates.h"
#include <iostream>
#include <string>
using namespace std;

//����������� ������ jobtitle �� ����� �����������
jobtitle::jobtitle(string j, int h, subordinates s) {
	jtitle = j;
	hourlycost = h;
	subs = s;
}

//����������� ������ jobtitle � ����� ����������
jobtitle::jobtitle(int x) {
	jtitle = to_string(x);
	hourlycost = x;
	subordinates s(x);
	subs = s;
}

//����������� ������ jobtitle ��� ����������
jobtitle::jobtitle() {
	jtitle = "";
	hourlycost = 0;
	subordinates s;
	subs = s;
}

//����� ����� ������ jobtitle
void jobtitle::input() {
	cout << "������� ���������: ";
	getline(cin, jtitle);
	cout << "������� ��������� ���� ������: ";
	cin >> hourlycost;
	subs.input();
}

//����� ������
void jobtitle::output() {
	cout << "���������: " << jtitle << endl;
	cout << "��������� ���� ������: " << hourlycost << endl;
	subs.output();
}