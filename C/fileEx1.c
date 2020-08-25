#include <stdio.h>

int main()
{
    FILE *pp;
    pp = fopen("test.dat", "w");
    fputc('A', pp);
    fputc('B', pp);
    fclose(pp);

    return 0;
}