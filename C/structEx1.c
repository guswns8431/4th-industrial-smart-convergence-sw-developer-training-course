#include <stdio.h>

int main()
{
    struct MT
    {
        int na;
        double ki;
    };
    struct MT M;
    M.na = 22;
    M.ki = 175.5;

    printf("%d %f", M.na, M.ki);

    return 0;
}