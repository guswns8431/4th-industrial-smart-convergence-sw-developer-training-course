#include <stdio.h>

int main()
{
    char m1, m2;
    printf("number1 = ");
    m1 = getchar();
    printf("number2 = ");
    getchar();
    m2 = getchar();

    switch (m1)
    {
    case 'a':
        printf("a");
        break;
    case 'B':
        printf("B");
        break;
    default:
        printf("끝");
        break;
    }

    return 0;
}