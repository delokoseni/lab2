#pragma once
class experience
{
	friend class employee;
public:
	experience(float w, int a, float m);
	experience(int x);
	experience();
	void input();
	void output();
	float monthstodecimal(int years, float month);
private:
	float workingyears; //���-�� ������� ������������ ���
	int army; //���-�� ��� � �����, ���� ����������� ������� �����
	float maternityleave; //���-�� ��� � ��������� �������, ���� ����������� ������� �����
};

