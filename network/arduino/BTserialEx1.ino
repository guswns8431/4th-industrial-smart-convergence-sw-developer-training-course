#include <SoftwareSerial.h>
#define pinTx 9
#define pinRx 10

SoftwareSerial BTser(pinTx,pinRx); //Tx,Rx순서 바뀌면 안됨

void setup(){
  Serial.begin(9600);
  Serial.println("Enter AT commands : ");
  BTser.begin(9600);
}

void loop(){
  if(BTser.available())
    Serial.write(BTser.read());
   if(Serial.available())
    BTser.write(Serial.read());
}
