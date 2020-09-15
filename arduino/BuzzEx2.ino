/*
 * tone()함수 사용없이, 악보 연주하기
 * 배열, 하수 라이브러리 만들기
 */
 #define keyPin 7
 const int bzPin = 2;
 int length = 25;
 
 /*악보-종이비행기*/
 char notes[] = "edcdeeedddeggedcdeeeddedc"; // 25개음
 
 /*음의 길이*/
 int beats[] = {3,1,2,2,2,2,4,2,2,4,2,2,4,3,1,2,2,2,2,4,2,2,3,1,8}; //음의 길이 16분 음표를 1로 기준(25개)
 
 /*연주속도*/
 int tempo = 100; //낮을수록 빠름
 
 /*부저 출력 함수*/
 void playTone(int tone, int duration){
  /*duration(us) = beats[i] x tempo x 1000
   duration의 크기가 커질 것을 대비 하여, 1000값을 강제 형변환
   tone은 주파수의 1/2에 해당 함으로, 주어진 HIGH시간(tone)의 2배만큼씩 이동한다. 
   즉, 1개의 주파수 이동 시간 만큼 지나므로, duration시간안에, 1개의 Pulse 증기삭의 시간 (tone시간의 2배) 간격으로 반복하게 만든다
   */
  for(long i = 0; i < duration * 1000L ; i+=tone*2){
    digitalWrite(bzPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(bzPin,LOW);
    delayMicroseconds(tone);
  }
 }

void playNote(char note, int duration){
  char names[] = { 'c','d','e','f','g','a','b','c'};
  int tones[] = {1915,1700,1519,1432,1275,1136,1014,956}; //1915 : 높은도 956 : 낮은도
  for(int i = 0 ; i < 8 ; i++){
    if(names[i] == note){
      playTone(tones[i],duration);
    }
  }
}

void setup(){
  pinMode(keyPin,INPUT_PULLUP);
  pinMode(bzPin,OUTPUT);
}

void loop(){
  /* 악보 : notes[],음갯수(length): 25개
   *  음길이(duration) : beats[] * tempo
   */
  boolean keyTch = digitalRead(keyPin);
  if(!keyTch){
    for(int i = 0; i < length; i++){
      if(notes[i] == ' '){ // 공백은 무음으로 건너뛰기
        delay(beats[i] * tempo);
      } else{ //음이 있으면, 연주하기, 음높이, 음길이 전달하기
        playNote(notes[i], beats[i] * tempo);
      }
      delay(tempo / 2); //반박자 지연시키기
    }
  }
}
