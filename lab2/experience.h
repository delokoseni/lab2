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
	int workingyears; //кол-во реально отработанных лет
	int army; //кол-во лет в армии, если сохранялось рабочее место
	int maternityleave; //кол-во лет в декретном отпуске, если сохранялось рабочее место
};

