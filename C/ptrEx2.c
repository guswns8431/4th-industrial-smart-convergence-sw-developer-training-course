#include <stdio.h>

int main()
{
    char M;
    char *mp;
    M = 'B';
    printf("a=%c\n",M);
    mp = &M;
    *mp = 'A';
    printf("a=%c\n",M);
}