#include <stdio.h>
#include <stdlib.h>
#include "reciprocal.hpp"

int main(int argc,char **argv)
{
	int i;
	i = atoi(argv[1]);
	//printf("Hello World\n");
	//printf("Number of arguments to the main function : %d\n",argc);
	//	for(i = 0 ; i < argc ; i++)
	//	{
	printf("argument numver %d is %g\n",i,reciprocal(i));
	//	}
	return 0;
}
