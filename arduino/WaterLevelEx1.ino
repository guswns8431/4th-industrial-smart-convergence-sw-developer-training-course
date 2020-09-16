#define pinWater A1
#define led1 2
#define led2 3
#define led3 4
#define buzAlarm 5

void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(pinWater,INPUT);
  pinMode(buzAlarm,OUTPUT);
  Serial.println("<<Water Level Monitor");
}

void loop(){
  int val = analogRead(pinWater);
  int lev = map(val,0,1023,0,100); //val의 범위가 0~1023이고 그 범위를 0~100까지를 바꾼다
  Serial.print("Water Level = ");
  Serial.print(lev);
  Serial.println(" % ");
  delay(100);
  if(lev <= 40){
    for(int i = 0 ; i < 3 ; i++)
    {
      digitalWrite(buzAlarm,LOW);
      delay(200);
      digitalWrite(buzAlarm,HIGH);
      delay(200);
    }
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    delay(500);
    Serial.println("Empty Water in Tank!!");
  }
  else if(lev > 40 && lev <= 60){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    delay(500);
    Serial.println("Low Level Water in Tank!!");
  }
  else if(lev > 60 && lev <= 80){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    delay(500);
    Serial.println("Midium Level Water in Tank!!");
  }
  else
  {
    for(int i = 0 ; i < 5 ; i++){
      digitalWrite(buzAlarm, LOW);
      delay(400);
      digitalWrite(buzAlarm,HIGH);
      delay(400);
    }
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    delay(500);
    Serial.println("High Level!! Stop the Valve!!");
  }
}
