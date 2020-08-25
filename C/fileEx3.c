#include <stdio.h>

int main()
{
    FILE *pp;
    FILE *ii;
    char m1, m2, m3, m4;
    char s1, s2, s3, s4;

    printf("첫문자? ");
    m1 = getchar();
    printf("둘째문자? ");
    getchar();
    m2 = getchar();
    printf("세째문자? ");
    getchar();
    m3 = getchar();
    printf("네째문자? ");
    getchar();
    m4 = getchar();

    pp = fopen("ch_log.dat", "w");
    fprintf(pp, "%c", m1);
    fprintf(pp, "%c", m2);
    fprintf(pp, "%c", m3);
    fprintf(pp, "%c", m4);
    fputs("\n\n..이상끝", pp);
    fclose(pp);

    ii = fopen("ch_log.dat", "r");
    s1 = fgetc(ii);
    s2 = fgetc(ii);
    s3 = fgetc(ii);
    s4 = fgetc(ii);
    printf("읽어들인 문자는 %c%c%c%c입니다.\n", s1, s2, s3, s4);
    fclose(ii);
}