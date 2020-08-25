#include <stdio.h>

int main()
{
    char m1, m2;

    printf("첫문자?");
    m1 = getchar();
    printf("둘째문자?");
    getchar();
    m2 = getchar();
    printf("%c와 %c를 입력함\n", m1, m2);

    /*문자열 입,출력하기*/
    char irum[20];
    char color[20];
    printf("꽃이름은?");
    scanf("%s", irum);

    printf("꽃이름은?");
    scanf("%s", color);

    printf("꽃 이름은 %s이고, 꽃색상은 %s입니다.\n", irum, color);
}