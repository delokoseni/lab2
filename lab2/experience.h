#pragma once
class experience
{
	friend class employee;
public:
	experience(int w, int a, int m);
	experience(int x);
	experience();
	void input();
	void output();
	float monthstodecimal();
private:
	int workingyears; //���-�� ������� ������������ ���
	int army; //���-�� ��� � �����, ���� ����������� ������� �����
	int maternityleave; //���-�� ��� � ��������� �������, ���� ����������� ������� �����
};

