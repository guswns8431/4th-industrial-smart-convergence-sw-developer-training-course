#include <stdio.h>

int main()
{
    struct MT
    {
        int na;
        double ki;
    };
    struct MT M;
    struct MT *mp;
    mp = &M;

    mp->na = 21;
    mp->ki = 174.2;

    printf("%d %f", M.na, M.ki);

    return 0;
}