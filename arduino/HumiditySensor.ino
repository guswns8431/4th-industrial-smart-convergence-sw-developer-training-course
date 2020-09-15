#include <DHT11.h> //외부 라이브러리 사용
#define pin 2
DHT11 dht(pin);

void setup(){
  pinMode(pin,INPUT);
  Serial.begin(9600);
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
