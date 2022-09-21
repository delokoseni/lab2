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
	int normal; //кол-во часов, отработанных по графику
	int overtime; //кол-во часов, отработанных сверхурочно
	int weekends; //кол - во часов, отработанных в выходные дни
};

