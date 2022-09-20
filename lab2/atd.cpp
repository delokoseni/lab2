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
	subordinates s = this->jt.getsubs();
	cout << "ID: " << this->id << endl;
	cout << "Стаж (отработано лет): " << this->exp.getworkingyears() << endl;
	cout << "Стаж (кол-во лет в армии): " << this->exp.getarmy() << endl;
	cout << "Стаж (кол-во лет в декретном отпуске): " << this->exp.getmaternityleave() << endl;
	cout << "Отработано часов за месяц(по графику): " << this->hour.getnormal() << endl;
	cout << "Отработано часов за месяц(сверхурочно): " << this->hour.getovertime() << endl;
	cout << "Отработано часов за месяц(в выходные дни): " << this->hour.getweekends() << endl;
	cout << "Должность: " << this->jt.getjtitle() << endl;
	cout << "Стоимость часа работы: " << this->jt.gethourlycost() << endl;
	cout << "Кол-во подчиненных: " << s.getamount() << endl;
	cout << "Средний стаж подчиненных: " << s.getasos() << endl << endl;
}

//метод короткого вывода employee
void employee::shortoutput() {
	cout << "ID: " << this->id << endl;
	cout << "Стаж: " << this->exp.getworkingyears() \
		+ this->exp.getarmy() + this->exp.getmaternityleave() << endl;
	cout << "Отработано часов за месяц: " << this->hour.getnormal() \
		+ this->hour.getovertime() + this->hour.getweekends() << endl;
	cout << "Должность: " << this->jt.getjtitle() << endl << endl;
}

//метод ввода employee
void employee::input() {
	cout << "Введите ID: ";
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
	float experience = this->exp.getworkingyears() + this->exp.getarmy() + this->exp.getmaternityleave();
	salary += this->hour.getnormal() * this->jt.gethourlycost();
	salary += this->hour.getovertime() * overtimecost;
	salary += this->hour.getweekends() * weekendscost;
	subordinates subs;
	//учет стажа
	if (expstatus == true)
		salary += salary / 100 * exppercent * experience;
	else
		salary += salary / 100 * exppercent * this->exp.getworkingyears();
	//учет наличия подчиненных
	subs = this->jt.getsubs();
	if (subs.getamount() && subsstatus)
		salary += subs.getamount() * salary / 100 * subspercent / subs.getasos();
	else
		salary += subs.getamount() * salary / 100 * subspercent;
	return salary;
}

//метод подсчета премии (положена или нет)
int employee::getpremium(int houramount) {
	if (this->hour.getnormal() + this->hour.getovertime() + this->hour.getweekends() < houramount)
		return 0;
	else
		return 1;
}