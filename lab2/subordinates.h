#pragma once
class subordinates
{
public:
	subordinates(int a, float A);
	subordinates(int x);
	subordinates();
	void input();
	void output();
private:
	int amount; //кол-во подчиненных
	float asos; //average seniority of subordinates - средний стаж подчиненных
};

