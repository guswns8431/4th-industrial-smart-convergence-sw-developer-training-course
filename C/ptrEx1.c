#include <stdio.h>

int main()
{
    int a;
    int *ap;
    a = 280;
    printf("a=%d\n", a);
    ap = &a;
    *ap = 435;
    printf("a=%d\n", a);

    return 0;
}