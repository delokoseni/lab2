#include "atd.h"

int main()
{
    Employee human1;
    char str[30] = "Менеджер";
    human1 = initiation(117, 5, 0, 0, 36, 4, 0, str, 140, 0, 0);
    output(human1);
    return 0;
}