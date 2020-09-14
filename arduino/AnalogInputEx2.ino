#define cds A0
#define led1 3
#define led2 5
#define led3 6
#define led4 11

void setup(){
  pinMode(cds,INPUT);
  pinMode(led1,OUTPUT);
  Serial.begin(9600);
  Serial.println("Light Value");
}

void loop(){
  unsigned int Lvalue = analogRead(cds); //0~1023
  int pValue = Lvalue /4; //10bit로 받은 값을 8bit로 바꾸기 위해서.0~255
  if(pValue > 100)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    delay(1000);
  }
  if(pValue >= 70 && pValue < 100)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    delay(1000);
  }
  if(pValue >= 40 && pValue < 70)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    delay(1000);
  }
  if(pValue >= 20 && pValue < 40)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    delay(1000);
  }
  if(pValue >= 0 && pValue < 20)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    delay(1000);
  }
  Serial.print("Light Value = ");
  Serial.print(Lvalue);
  Serial.print(" -> LED Value = ");
  Serial.println(pValue);
  delay(1000);
}
