#pragma once

class hours
{
	friend class employee;
public:
	hours(int n, int o, int w);
	hours(int x);
	hours();
	void input();
	void output();
private:
	int normal; //���-�� �����, ������������ �� �������
	int overtime; //���-�� �����, ������������ �����������
	int weekends; //��� - �� �����, ������������ � �������� ���
};

