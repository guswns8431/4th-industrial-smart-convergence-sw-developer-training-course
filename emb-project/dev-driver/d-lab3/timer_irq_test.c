#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int dev;
    char key;
    unsigned int buff;
    dev = open("/dev/timer_irq",O_RDWR);
    if(dev < 0){
        printf("device open fail\n");
        return 0;
    }
    printf("open dev : %d\n",dev);
    printf("\n\nlook at led !!!\n that is turned on and off by irq\n\n");
    while(1){
        printf("press q and return key to exit\n");
        printf("any other key will show you TCNT0 register\n");
        key = getchar();
        if(key == 'q') break;
        read(dev, &buff, sizeof(unsigned int));
        printf("cnt : %d\n\n",buff);
    }
    close(dev);
    return 0;
}
