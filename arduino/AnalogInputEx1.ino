#define cds A0
#define led 3

void setup(){
  pinMode(cds,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  Serial.println("Light Value");
}

void loop(){
  unsigned int Lvalue = analogRead(cds);
  int pValue = Lvalue /4; //10bit로 받은 값을 8bit로 바꾸기 위해서
  if(pValue > 100)
  {
    analogWrite(led,255); //LED OFF
  }
  else
  {
    analogWrite(led,pValue); // LED Bright.어두울수록 밝아짐
  }
  Serial.print("Light Value = ");
  Serial.print(Lvalue);
  Serial.print(" -> LED Value = ");
  Serial.println(pValue);
  delay(1000);
}
