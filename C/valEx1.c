#include <stdio.h>

static int a = 100;
static int b = 3;

void haha()
{
    printf("%d %d\n",a,b);
    a = 20;
}
void hoho()
{
    printf("%d %d\n",a,b);
    b = 10;
}

int main()
{
    haha();
    hoho();
    printf("%d %d",a,b);

    return 0;
}