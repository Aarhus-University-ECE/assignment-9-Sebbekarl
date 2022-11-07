#include "sum.h"

int sum(int a[], int n)
{
    /* checks the different conditions and handles them according to the description */
    if (n == 0)
        return 0;
    if (n > 0)
        return a[n - 1] + sum(a, n - 1);
}