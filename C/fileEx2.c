#include <stdio.h>

int main()
{
    FILE *pp;
    pp = fopen("test.dat","w");
    fputs("GOOD\n",pp);
    fputc('B',pp);
    fclose(pp);
}