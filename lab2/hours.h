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
	int allhours();
private:
	int normal; //���-�� �����, ������������ �� �������
	int overtime; //���-�� �����, ������������ �����������
	int weekends; //��� - �� �����, ������������ � �������� ���
};

