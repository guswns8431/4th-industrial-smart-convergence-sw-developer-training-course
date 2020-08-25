#include <stdio.h>

int main()
{
    char m1,m2;
    printf("number1 = ");
    m1 = getchar();
    getchar();
    printf("number2 = ");
    
    m2 = getchar();
    if(m1 > 0)
    {
        printf("%d",m1);
    }
    else if(m2>m1)
    {
        printf("%d가 %d보다 더 크다",m2,m1);
    }
    else
    {
        printf("%d기 %d보다 더 크다",m1,m2);
    }

    return 0;
    
}