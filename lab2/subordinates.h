#pragma once
class subordinates
{
public:
	subordinates(int a, float A);
	subordinates(int x);
	subordinates();
	int getamount();
	float getasos();
	void input();
private:
	int amount; //���-�� �����������
	float asos; //average seniority of subordinates - ������� ���� �����������
};

