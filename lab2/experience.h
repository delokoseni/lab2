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
	float workingyears; //кол-во реально отработанных лет
	int army; //кол-во лет в армии, если сохранялось рабочее место
	float maternityleave; //кол-во лет в декретном отпуске, если сохранялось рабочее место
};

