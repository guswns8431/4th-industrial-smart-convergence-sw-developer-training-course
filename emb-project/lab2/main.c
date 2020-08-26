#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int fd,count;
	char buf[512];
	if(argc < 2)
	{
		printf("usage : %s filename [string]\n",argv[1]);
		return 1;
	}
	if((fd = open(argv[1], O_RDWR | O_CREAT)) < 0)
	{
		perror("open error");
		return 1;
	}
	if(argc >= 3)
	{
		count = write(fd,argv[2],strlen(argv[2]));
		printf("write to file %d byte\n",count);
	}
	else
	{
		count = read(fd,buf,512);
		printf("read from file %d byte\n",count);
		printf("%s\n",buf);
	}
	close(fd);
}
