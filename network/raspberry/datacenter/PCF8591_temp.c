#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#include <math.h>

#define PCF 120
#define D0pin 0

void Print(int x){
    switch (x)
    {
    case 0:
        printf("\n**************\n");
        printf("too hot");
        printf("************\n\n");
        break;
    case 1:
        printf("\n**************\n");
        printf("better");
        printf("************\n\n");
        break;
    default:
        printf("\n**************\n");
        printf("print value error");
        printf("************\n\n");
        break;
    }
}

int main(){
    unsigned char a0pin,a1pin,a2pin,a3pin;
    double Vr, Rt, temp;
    float a0_lux,a1_temp,a2_lux,a3_volt;
    int tmp, status;

    if(wiringPiSetup() == -1)
    {
        printf("setup WiringPi failed");
        return 1;
    }

    pcf8591Setup(PCF,0x48);
    pinMode(D0pin,INPUT);
    status = 0;
    while (1)
    {
        printf("*******loop*******\n");
        a0pin = analogRead(PCF+0);
        a1pin = analogRead(PCF+1);
        a2pin = analogRead(PCF+2);
        a3pin = analogRead(PCF+3);
        printf("a0 = %ld",a0pin);
        printf("; a1 = %ld",a1pin);
        printf("; a2 = %ld",a2pin);
        printf("; a3 = %ld",a3pin);
        
        //LDR0 센서의 조도값 계산
        a0_lux = 3.92 * (float)(255 - a0pin);

        //온도센서
        Vr = 5 * (double)a1pin/255;
        Rt = 10000 *(double)Vr/(5-(double)Vr);
        temp = 1/(((log(Rt/10000))/3950)+(1/(273.15+25)));
        temp = -(temp - 273.15);

        //LDR2 센서의 조도값 계산
        a2_lux = 3.92 * (float)a2pin;

        //Potentio meter의 전압 분배값 계산
        a3_volt = 0.02 * (float)a3pin;

        printf("\n");
        printf("lu-1: %lf lx ; ",a0_lux);
        printf("Current temperature: %lf 'C ; ", temp);
        printf("lu-2: %lf lx ; ",a2_lux);
        printf("POT.Voltage : %lf V\n",a3_volt);
        tmp = digitalRead(D0pin);
        if(tmp != status){
            Print(tmp);
            status = tmp;
        }
        delay(500);
    }

    return 0;
    
}
