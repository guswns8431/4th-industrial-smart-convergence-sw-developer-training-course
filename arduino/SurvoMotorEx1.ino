#include <Servo.h>
int servPin = 3;
int state;
Servo servo;
int angle = 0;

void setup(){
  Serial.begin(9600);
  servo.attach(servPin);
  Serial.println("**Welcome to Servo Control**");
  Serial.println("**This is Ceremoney**");
  for(angle = 0; angle < 100 ; angle++){
   servo.write(angle);
   delay(15);
   }

   for(angle = 100; angle > 0; angle--){
   servo.write(angle);
   delay(15);
   }
   
}

void loop() {
  if(state ==0){
    Serial.println("System ready to Control...");
    Serial.print("Put Angle to turn : ");
    state = 1;
    servo.detach();
  }
  if(Serial.available()){
    angle = Serial.parseInt(); //읽은 데이터를 int형으로 변환
    Serial.println(angle);
    state = 2;
  }
  if(state == 2){
    servo.attach(servPin);
    Serial.println("++Servo Working!!");
    servo.write(angle);
    delay(500);
    // at least > 50ms, if lower time not enough to reach
    state = 0;
  }
}
