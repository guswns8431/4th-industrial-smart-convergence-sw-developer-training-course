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
  boolean reading = digitalRead(sw1); //상시로 버튼상태 읽기. 스위치가 눌려졌는지 계속 확인
  
  if(reading != lastBtnState) // 현재 버튼값이 직전의 버튼상태와 같지 않으면
  {
    // 버튼 값 표시
    if(!reading) 
    {
      Serial.print(reading);
      Serial.print("\nlastBtnState = ");
      Serial.println(lastBtnState);
    }
    
    //상태변화시 시간 확인, Flag 설정
    Serial.println("first Check");
    lastDebounceTime = millis();
    btnFlag = 1;
    Serial.print("lastTime = ");
    Serial.println(lastDebounceTime);
  }
  
  //상태 변화 이후 시간 감시(버튼의 채터링 대기), 상태 변화 다시 확인
  if((millis()-lastDebounceTime) > debounceDelay && lastDebounceTime != 0) //변화가 있다면 lastDebounceTime이 변화가 있기 때문에 변화가 있는지 확인 
  {
    Serial.print("debounceTime = ");
    Serial.print(millis()-lastDebounceTime);
    Serial.print(" ; reading = ");
    Serial.print(reading);
    Serial.print(" ; lastBtnState = ");
    Serial.print(lastBtnState);
    Serial.print(" ; btnFlag  = ");
    Serial.print(btnFlag);
    Serial.print(" ; btnState = ");
    Serial.println(btnState);

    Serial.print(" ; ledState = ");
    Serial.println(ledState);
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
