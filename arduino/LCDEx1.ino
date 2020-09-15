/*
 * LCD 연결하기 + 시리얼모니터 설정 알아보기
 */
 #include<Wire.h> // 직렬통신을 다루는 헤더파일
 #include<LiquidCrystal_I2C.h> //라이브러리 매니저를 통해서 외부 라이브러리 추가
 LiquidCrystal_I2C lcd(0x27,5,4); //address,SCL,SDA. 위의 라이브러리에서 구현되어 있는 클래스. address주소는 따로 확인 할 수 있음(코드가 있음 따로.보통 0x27). 
 String data;
 
 void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("LCD TEST");
  delay(1000);
 }

 void loop(){
  lcd.clear();
  if(Serial.available()) //Serial.available : 선로가 구성되어 있고, 무언가의 데이터가 있다면 가져옴, 가져오고 나면 그 안의 데이터는 사라짐
  {
    data = Serial.readString(); // 받아들인 데이터를 data로 저장
  }

  lcd.setCursor(0,1); //글자를 찍어야하는 위치를 설정
  lcd.print(data);
  delay(500);
 }
