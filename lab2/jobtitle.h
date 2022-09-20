#pragma once
#include "subordinates.h"

//АТД должность
typedef struct jobtitle {
	char* jtitle; //наименование должности
	int hourlycost; //стоимость часа работы
	Subordinates subs; //подчиненные
}Jobtitle;
