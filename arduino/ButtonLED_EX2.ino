/*
 * Button LED without Delay() 실습
 */
const int led1 = 4; // led를 몇 번에 연결할건지 설정.4에 연결
const int sw1 = 2;

//상태변수
boolean ledState = HIGH;
boolean btnState;
boolean lastBtnState = LOW;
int btnFlag = 0;

//Btn 채터링 방지 변수
long lastDebounceTime = 0;
long debounceDelay = 49;

void setup() {
  // put your setup code here, to run once:
  // 한번 수행. 작동을 하기 위한 기본 준비동작 설정
  pinMode(led1,OUTPUT); //led1이라는 변수가 output이다. 이떄부터 led1이라는 변수를 아두이노가 사용할 수 있음.
  pinMode(sw1,INPUT);
  digitalWrite(led1,ledState);
  Serial.begin(9600);
  Serial.println("Time to read at setup"); //수신처에서 이 내용이 보여야 제대로 통신이 되고 있다는 뜻
}

void loop() {
  // put your main code here, to run repeatedly:
  // 계속 수행되는 내용
  boolean reading = digitalRead(sw1); //switch의 값을 읽어와서 reading이라는 변수에 저장
  if(reading != lastBtnState)
  {
    lastDebounceTime = millis();
    btnFlag = 1;
  }

  if((millis()-lastDebounceTime) > debounceDelay && lastDebounceTime != 0) //delay함수 없이 스위치 제어
  {
    if(btnFlag)
    {
      btnState = !btnState;
    }
    if(btnState == HIGH)
    {
      ledState = !ledState;
      btnFlag = 1;
    }
    lastDebounceTime = 0;
  }

  if(btnFlag == 1)
  {
    digitalWrite(led1,ledState);
  }

  lastBtnState = reading;
}
