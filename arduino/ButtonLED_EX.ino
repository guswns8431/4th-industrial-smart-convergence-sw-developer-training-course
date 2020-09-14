int led1 = 4; // led를 몇 번에 연결할건지 설정.4에 연결
//#define led1 4 이런식으로 초기화하기도함
#define sw1 2

void setup() {
  // put your setup code here, to run once:
  // 한번 수행. 작동을 하기 위한 기본 준비동작 설정
  pinMode(led1,OUTPUT); //led1이라는 변수가 output이다. 이떄부터 led1이라는 변수를 아두이노가 사용할 수 있음.
  pinMode(sw1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 계속 수행되는 내용
  boolean reading = digitalRead(sw1); //switch의 값을 읽어와서 reading이라는 변수에 저장
  if(reading) //switch를 누르면 reading변수가 0이 됨, 안 누른 상태가 1
  {
    digitalWrite(led1,HIGH); // off
    delay(1000);
  }
  else
  {
    digitalWrite(led1,LOW); // on
    delay(1000);
  }
/*
  digitalWrite(led1,HIGH); // off
  delay(1000); //delay가 있어야 위의 코드를 계속 유지하고 사람이 육안으로 확인할 수 있는 상태가 된다. delay가 없으면 사람이 육안으로 확인하기 힘듦
  digitalWrite(led1,LOW); // on
  delay(1000);
*/
}
