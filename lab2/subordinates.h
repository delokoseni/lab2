#pragma once

class subordinates
{
	friend class employee;
public:
	subordinates(int a, float A);
	subordinates(int x);
	subordinates();
	void input();
	void output();
	float averageseniority(int number);
private:
	int amount; //���-�� �����������
	float asos; //average seniority of subordinates - ������� ���� �����������
};

