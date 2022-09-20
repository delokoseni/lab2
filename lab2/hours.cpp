#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "hours.h"

//функци€ ввода структуры hours
Hours inputhour() {
	Hours hour;
	int normal, overtime, weekends;
	printf("¬ведите кол-во отработанных за мес€ц часов: ");
	scanf("%d", &normal);
	printf("¬ведите кол-во сверхурочных часов : ");
	scanf("%d", &overtime);
	printf("¬ведите кол-во отработанных за мес€ц часов в выходные: ");
	scanf("%d", &weekends);
	if (overtime > 0)
		normal -= overtime;
	if (weekends > 0)
		normal -= weekends;
	hour.normal = normal;
	hour.overtime = overtime;
	hour.weekends = weekends;
	return hour;
}