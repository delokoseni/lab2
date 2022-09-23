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
int getsalary(Employee human, int overtimecost, int weekendscost, int exppercent, \
	int expstatus, int subspercent, int subsstatus);
int getpremium(Employee human, int houramount);
int allhours(Hours hour);
float averageseniority(int number);
Subordinates inputsubs();
Jobtitle inputjt();
Hours inputhour();
Experience inputexp();
Experience expinitiation(int workingyears, int army, int maternityleave);
Hours hourinitiation(int normal, int overtime, int weekends);
Jobtitle jtinitiation(char jtitle[], int hourlycost, int amount, float asos);
void expoutput(Experience exp);
void houroutput(Hours hour);
void jtoutput(Jobtitle jt);
int monthstodecimal(Experience exp);
float comparisonhc(Jobtitle jt, int hc);