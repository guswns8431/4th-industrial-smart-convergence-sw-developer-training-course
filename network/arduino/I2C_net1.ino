#include <Wire.h>
#include <math.h>
#include <LiquidCrystal_I2C.h>
#include <MECHA_PCF8591.h>
#define i2c_scl A5
#define i2c_sda A4

LiquidCrystal_I2C lcd(0x27,i2c_scl, i2c_sda);
MECHA_PCF8591 pcf;

float a0_lux, a2_lux,a3_volt;
double a1_temp;

void setup(){
  Wire.begin();
  Serial.begin(9600);
}

void loop(){
  int a0_in = pcf.analogRead(0); //조도센서
  delay(500);
  int a1_in = pcf.analogRead(1); //온도센서
  delay(500);
  int a2_in = pcf.analogRead(2); //추가한 조도센서
  delay(500);
  int a3_in = pcf.analogRead(3); //pot.data
  delay(500);
  Serial.print("LDR = "); Serial.print(a0_in);
  Serial.print("; temp = "); Serial.print(a1_in);
  Serial.print("; LDR2 = "); Serial.print(a2_in);
  Serial.print("; POT = "); Serial.println(a3_in);

  //LDR0 센서의 조도값 계산
  a0_lux = 3.92 * a0_in;
  
  //temp 센서의 온도값 계산
  double Vr = 5 * (double)a1_in / 255;
  double Rt = 10000 * Vr /(5-Vr);
  a1_temp = 1/(((log(Rt/10000)/3950) + (1/(273.15+25))));
  a1_temp = -(a1_temp - 273.15);
  
  //LDR2 센서의 조도값 계산
  a2_lux = 3.92 * (float)a2_in;
  
  //Potentio meter의 전압 분배값 계산
  a3_volt = 0.02 * (float)a3_in;

  Serial.print("luminance-1 = "); Serial.print(a0_lux); Serial.println("[lx]");
  Serial.print("temperature = "); Serial.print(a1_temp); Serial.println("['C]");
  Serial.print("luminance-2 = "); Serial.print(a2_lux); Serial.println("[lx]");
  Serial.print("POT. Voltage = "); Serial.print(a3_volt); Serial.println("[V]");
  
  /*
  if(Serial.available()){
    int dValue = Serial.parseInt();
    pcf.analogWrite(dValue);
  }
  */
}
