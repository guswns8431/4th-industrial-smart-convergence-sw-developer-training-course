#include <stdio.h>

int main()
{
    FILE *pp;

    int nai;
    float ki;
    pp = fopen("mr.rep", "w");
    nai = 45;
    ki = 156.4;
    fprintf(pp, "%40s\n\n", "*인물정보*");
    fprintf(pp, "%30s=%9s\n\n", "이름", "홍길동");
    fprintf(pp, "%30s=%09d\n\n", "나이", nai);
    fprintf(pp, "%20s=%9.2f\n\n", "키", ki);
    fputs("\n\n\n.. 이상 끝", pp);
    fclose(pp);
}