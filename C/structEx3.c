#include <stdio.h>

int main()
{
    struct SCORE
    {
        char hakjum;
        int jumsu;
    };
    struct SCORE S;
    S.hakjum = 'A';
    S.jumsu = 92;
    puts("<성적>");
    printf("%d점은 %c학점\n", S.jumsu, S.hakjum);
    printf("S구조체는 %lu바이트입니다", sizeof(S));

    return 0;
}