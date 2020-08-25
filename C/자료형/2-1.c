#include <stdio.h>

int main()
{
    /*여러줄의 주석문
    *주로 프로그램의 첫머리에 작성
    * 또는, 새로운 단락을 알리는 용도
    * **/
   //한줄짜리 주석문 : 주로 간단한 설명을 첨부함
   /*정수형 상수*/
   printf("정수값 출력 : "); printf("%d\n",10);
   /*실수형 상수*/
   printf("실수값 출력 : "); printf("%f\n",120.45);
   printf("지수값 출력 : "); printf("%e\n",120.45);
   /*문자형 상수 : 하나의 글자를 다룸,'' 사용*/
   char A;
   A = 65; //A의 ascii값은 65
   printf("문자값 출력 : "); printf("%c\n",A);
   printf("문자(A)의 bytes수 출력 : "); printf("%ld\n",sizeof(A));
   /*문자열 ㅇ상수 : 하나이상의 글자를 다룸,""사용*/
   printf("문자열 출력 : "); printf("%s\n","String Value");
   printf("문자열(S***)의 bytes수 출력 : "); printf("%ld\n",sizeof("String Value"));
   //문자열을 표현하면,'0'(NULL값 이라고함.)이 문자열끝에 자동추가(즉, 1byte가 증가한다)
}