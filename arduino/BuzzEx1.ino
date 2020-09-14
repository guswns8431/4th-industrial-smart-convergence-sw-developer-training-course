#define C 262 //도(262Hz)
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494

#define keyPin 7
const int bzPin = 2;
int pos = 0;
int tempo = 200;
unsigned int state = 0;

void setup(){
  pinMode(keyPin,INPUT);
  pinMode(bzPin,OUTPUT);
  Serial.begin(9600);  
}

void loop(){
  boolean keyTch = digitalRead(keyPin);
  if(!keyTch)
  {
    pos++;
  }
  delay(200);
  switch(pos)
  {
    case 1:
      if(state != 11)
      {
        tone(bzPin,C,tempo);
        state = 11; 
      }
      break;
    case 2:
      if(state != 22)
      {
        tone(bzPin,D,tempo);
        state = 22; 
      }
      break;
     case 3:
      if(state != 33)
      {
        tone(bzPin,E,tempo);
        state = 33; 
      }
      break;
     case 4:
      if(state != 44)
      {
        tone(bzPin,F,tempo);
        state = 44; 
      }
      break;
     case 5:
      if(state != 55)
      {
        tone(bzPin,G,tempo);
        state = 55; 
      }
      break;
     case 6:
      if(state != 66)
      {
        tone(bzPin,A,tempo);
        state = 66; 
      }
      break;
     case 7:
      if(state != 77)
      {
        tone(bzPin,B,tempo);
        state = 77; 
      }
      break;
     case 8:
      Serial.println("End : No Sounds!");
      break;
     default: 
      pos = 0;
      break;
  }
}
