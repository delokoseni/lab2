#pragma once
class experience
{
public:
	experience(float w, int a, float m);
	experience(int x);
	experience();
	void input();
	void output();
private:
	float workingyears; //���-�� ������� ������������ ���
	int army; //���-�� ��� � �����, ���� ����������� ������� �����
	float maternityleave; //���-�� ��� � ��������� �������, ���� ����������� ������� �����
};

