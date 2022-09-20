#pragma once

//ј“ƒ отработанные за мес€ц часы
typedef struct hours {
	int normal; //кол-во часов, отработанных по графику
	int overtime; //кол-во часов, отработанных сверхурочно
	int weekends; //кол - во часов, отработанных в выходные дни
}Hours;

