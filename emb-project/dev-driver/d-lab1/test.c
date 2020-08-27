#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	printf("Hello World\n");
	printf("입력한 단어수는: %d\n", argc-1);
	for(i=1;i<argc;i++)
	{
		printf("입력한 단어%d는 %s\n", i,argv[i]);
	}
	return 0;
}
