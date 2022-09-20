#pragma once
class hours
{
public:
	hours(int n, int o, int w);
	hours(int x);
	hours();
	int getnormal();
	int getovertime();
	int getweekends();
	void input();
private:
	int normal; //кол-во часов, отработанных по графику
	int overtime; //кол-во часов, отработанных сверхурочно
	int weekends; //кол - во часов, отработанных в выходные дни
};

