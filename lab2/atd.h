#pragma once
#include "experience.h"
#include "hours.h"
#include "subordinates.h"
#include "jobtitle.h"

//ј“ƒ —отрудник
typedef struct employee {
	int id; //индивидуальный номер
	Experience exp; //стаж
	Hours hour; //отработанные за мес€ц часы
	Jobtitle jt; //должность

} Employee;

Employee initiation(int id, float workingyears, int army, float maternityleave,
	int normal, int overtime, int weekends, char jtitle[], int hourlycost, int amount, float ASoS);
Employee input();
void output(Employee human);
void shortoutput(Employee human);
void shortoutput(Employee human);
int getsalary(Employee human, int overtimecost, int weekendscost, int exppercent, \
	int expstatus, int subspercent, int subsstatus);
int getpremium(Employee human, int houramount);