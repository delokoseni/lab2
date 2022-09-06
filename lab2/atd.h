#pragma once
//АТД Сотрудник
typedef struct employee {
	int id; //индивидуальный номер
	//АТД стаж
	typedef struct experience {
		int workingyears; //кол-во реально отработанных лет
		int army; //кол-во лет в армии, если сохранялось рабочее место
		int maternityleave; //кол-во лет в декретном отпуске, если сохранялось рабочее место
	}Experience;
	//АТД отработанные за месяц часы
	typedef struct hours {
		int normal; //кол-во часов, отработанных по графику
		int overtime; //кол-во часов, отработанных сверхурочно
		int weekends; //кол - во часов, отработанных в выходные дни
	}Hours;
	//АТД должность
	typedef struct jobtitle {
		int hourlycost; //стоимость часа работы
		//АТД подчиненные
		typedef struct subordinates {
			int amount; //кол-во подчиненных
			int ASoS; //average seniority of subordinates - средний стаж подчиненных
		}Subordinates;
	}Jobtitle;
} Employee;
//функция инициализации
void initiation(Employee human, int id, int workingyears, int army, int maternityleave,
	int normal, int overtime, int weekends, int hourlycost, int amount, int ASoS){

}
//функция ввода
void input(Employee human) {

}
//функция вывода
void output(Employee human) {

}
//функция подсчета зарплаты
int Salary(Employee human) {
	int salary = 0; //зарплата
	return salary;
}
//функция подсчета премии
int Premium(Employee human) {
	int premium = 0; //премия
	return premium;
}