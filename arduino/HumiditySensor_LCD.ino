#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h> //외부 라이브러리 사용
/*DHT11*/
#define pin 2
DHT11 dht(pin);
/*LCD*/
LiquidCrystal_I2C lcd(0x27,5,4); //address,SCL,SDA

void setup(){
  pinMode(pin,INPUT);
  Serial.begin(9600);
  /*LCD 초기화*/
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Humi.Temp.");
  delay(1000);
  Serial.println("Start DHT11!!");
}

void loop() {
  int err;
  float temp,humi; //온도,습도
  if((err=dht.read(humi,temp)) == 0){
    Serial.print("temperature = ");
    Serial.print(temp);
    Serial.print(", humidity = ");
    Serial.print(humi);
    Serial.print("%");
    
    /*lcd*/
    lcd.setCursor(0,1);
    lcd.print(temp);
    lcd.print("'C");
    lcd.setCursor(9,1);
    lcd.print(humi);
    lcd.print("%");
  }
  else
  {
    Serial.println();
    Serial.print("Error NO : ");
    Serial.print(err);
    Serial.println();
  }
  delay(1000);
}
