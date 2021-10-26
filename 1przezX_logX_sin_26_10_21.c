#include <stdlib.h>
#include <iostream>
#define M_PI 3.14159265358979323846


int main(void)
{
    int i;
    printf("Liczba:\t\t1/x:\t\t\tlog10(x):\t\tsin(x/20 * 2pi):\n\n");
    for (i = 1; i < 11; ++i)
     printf("%d:\t\t\%.5Lf\t\t\t%.5Lf\t\t\t%.5Lf\n", i, (1.0 / i), log10(i), sin(i / (20 * 2 * M_PI)));
}

