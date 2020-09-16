#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#define IR_KEY_1 0xFF6897
#define IR_KEY_2 0xFF18E7
#define IR_KEY_3 0xFF7A85

#define C 262
int tempo = 200;

int relay_led = 4; //Relay_S
int remote = 7;
int buzz = 8;
int led = 5;

IRrecv irrecv(remote);
decode_results result;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(remote,INPUT);
  pinMode(relay_led,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.println("**Start Remote Test**");
}

void loop(){
  if(irrecv.decode((&result))){
    Serial.println(result.value, HEX);
    decodeIR();
    irrecv.resume();
  }
}

void decodeIR(){
  switch(result.value){
    case IR_KEY_1:
      digitalWrite(relay_led, HIGH); //NO - on
      delay(1000);
      digitalWrite(relay_led, LOW);
      break;
    case IR_KEY_2:
      for(long i = 0 ; i < 300000L ; i+=1915*2)
      {
        digitalWrite(buzz,HIGH);
        delayMicroseconds(1915);
        digitalWrite(buzz,LOW);
        delayMicroseconds(1915);
      }
      break;
     case IR_KEY_3:
      digitalWrite(relay_led,HIGH);
      delay(1000);
      digitalWrite(relay_led, LOW);
      break;
     default:
      break;
  }
}

