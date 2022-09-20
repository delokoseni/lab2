#include "atd.h"

//конструктор класса employee со всеми параметрами
employee::employee(int i, experience e, hours h, jobtitle j) {
	id = i;
	exp = e;
	hour = h;
	jt = j;
}

//конструктор класса employee с одним параметром
employee::employee(int x) {
	id = x;
	experience e(x);
	hours h(x);
	jobtitle j(x);
	exp = e;
	hour = h;
	jt = j;
}

//конструктор класса employee без параметров
employee::employee() {
	id = 0;
	experience e;
	hours h;
	jobtitle j;
	exp = e;
	hour = h;
	jt = j;
}

//метод полного вывода employee
void employee::output() {
	cout << "ID: " << this->id << endl;
	exp.output();
	hour.output();
	jt.output();
}

//метод короткого вывода employee
void employee::shortoutput() {
	//cout << "ID: " << this->id << endl;
	//cout << "—таж: " << this->exp.getworkingyears() \
	//	+ this->exp.getarmy() + this->exp.getmaternityleave() << endl;
	//cout << "ќтработано часов за мес€ц: " << this->hour.getnormal() \
	//	+ this->hour.getovertime() + this->hour.getweekends() << endl;
	//cout << "ƒолжность: " << this->jt.getjtitle() << endl << endl;
}

//метод ввода employee
void employee::input() {
	cout << "¬ведите ID: ";
	cin >> this->id;
	exp.input();
	hour.input();
	while (getchar() != '\n');
	jt.input();
}

//метод подсчета зарплаты
int employee::getsalary(int overtimecost, int weekendscost, int exppercent, \
	int expstatus, int subspercent, int subsstatus) {
	int salary = 0; //зарплата
	//float experience = this->exp.getworkingyears() + this->exp.getarmy() + this->exp.getmaternityleave();
	//salary += this->hour.getnormal() * this->jt.gethourlycost();
	//salary += this->hour.getovertime() * overtimecost;
	//salary += this->hour.getweekends() * weekendscost;
	//subordinates subs;
	////учет стажа
	//if (expstatus == true)
	//	salary += salary / 100 * exppercent * experience;
	//else
	//	salary += salary / 100 * exppercent * this->exp.getworkingyears();
	////учет наличи€ подчиненных
	//subs = this->jt.getsubs();
	//if (subs.getamount() && subsstatus)
	//	salary += subs.getamount() * salary / 100 * subspercent / subs.getasos();
	//else
	//	salary += subs.getamount() * salary / 100 * subspercent;
	return salary;
}

//метод подсчета премии (положена или нет)
int employee::getpremium(int houramount) {
	/*if (this->hour.getnormal() + this->hour.getovertime() + this->hour.getweekends() < houramount)
		return 0;
	else*/
		return 1;
}