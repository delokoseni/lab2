#pragma once
//��� ���������
typedef struct employee {
	int id; //�������������� �����
	//��� ����
	typedef struct experience {
		int workingyears; //���-�� ������� ������������ ���
		int army; //���-�� ��� � �����, ���� ����������� ������� �����
		int maternityleave; //���-�� ��� � ��������� �������, ���� ����������� ������� �����
	}Experience;
	//��� ������������ �� ����� ����
	typedef struct hours {
		int normal; //���-�� �����, ������������ �� �������
		int overtime; //���-�� �����, ������������ �����������
		int weekends; //��� - �� �����, ������������ � �������� ���
	}Hours;
	//��� ���������
	typedef struct jobtitle {
		int hourlycost; //��������� ���� ������
		//��� �����������
		typedef struct subordinates {
			int amount; //���-�� �����������
			int ASoS; //average seniority of subordinates - ������� ���� �����������
		}Subordinates;
	}Jobtitle;
} Employee;
//������� �������������
void initiation(Employee human, int id, int workingyears, int army, int maternityleave,
	int normal, int overtime, int weekends, int hourlycost, int amount, int ASoS){

}
//������� �����
void input(Employee human) {

}
//������� ������
void output(Employee human) {

}
//������� �������� ��������
int Salary(Employee human) {
	int salary = 0; //��������
	return salary;
}
//������� �������� ������
int Premium(Employee human) {
	int premium = 0; //������
	return premium;
}