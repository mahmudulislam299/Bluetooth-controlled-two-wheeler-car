/* Mahmudul Islam
 * EEE,Bangladesh University of Engineering and Technology (BUET)
 * Email: mahmudulislam299@gmail.com
 * Project: Mechanical Festival: Fury Race Competition 2016
 */

#define inA 4///right
#define inB 5///right
#define inC 6///left
#define inD 7///left
#define ena 9
#define enb 8
#include <SoftwareSerial.h>

#define Buzzer 2 // buzzer for sound

SoftwareSerial mySerial(10, 11); // RX, TX
void mot_init();
char p;
int v = 180;


void setup() {
    void  mtr_strt();
    Serial.begin(9600);
    while (!Serial) {
    }
    Serial.println("HELLO FURY RACE!!!!!!!!!");

    mySerial.begin(9600);//4800
    mySerial.println("Hello, helix heptagon");
    pinMode(Buzzer,OUTPUT);
    
}

void loop() {
  if (mySerial.available()) {
    p = mySerial.read();
    if(p!='S'){
  Serial.println(p);}}

  switch (p) { //for speed control
  case '0' :
  v=20;
  break;
  case '1' :  
  v=60;  
  break;
  case '2' :
  v=80;
  break;
  case '3':
  v=100;
  break;
  case '4':
  v=120;
  break;
  case '5':
  v=140;
  break;
  case '6':
  v=180;
  break;
  case '7':
  v=200;
  break;
  case '8':
  v=220;
  break;
  case 'q':
  v=250;
  break;
}

  if(p=='X')
  {
    bell();
   }

    else if(p=='x')
  {
    bell();
    delay(100);
    bell();
   }
  else if(p=='x')
   {
    //bell();
    //delay(5);
    //bell();
   }
    
  if(p=='F')
  {
    _speed(v , v);
  }

  else if(p=='B')
  {
    _speed(-v, -v);
  }

  if(p=='R')
  {
   _speed(v, -v);
  }

  if(p=='L')
  {
   _speed(-v, v);
  }

  if(p=='G')
  {
    _speed(50, v);
  }

  if(p=='I')
  {
    _speed(v, 50);
  }

  if(p=='H')
  {
    _speed(-50, -v);
  }

  if(p=='J')
  {
    _speed(-v, -50);
  }

  if(p=='S')
  {
    _speed(0,0);
  }
    
}


void mtr_strt() //motor intialization
{
  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(inC,OUTPUT);
  pinMode(inD,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  
  digitalWrite(inA,HIGH);
  digitalWrite(inB,HIGH);
  digitalWrite(inC,HIGH);
  digitalWrite(inD,HIGH);
}

void bell()
{
  analogWrite(Buzzer, 255);
  delay(500);
  analogWrite(Buzzer,0);
 
}





void _speed(int lm, int rm)       
{
 if(lm==0)                 
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,HIGH);
  }
  if(lm>0)
  {
    digitalWrite(inC,HIGH);        
    digitalWrite(inD,LOW);
  }
  else if(lm<0)
  {
    digitalWrite(inC,LOW);          
    digitalWrite(inD,HIGH);
  }


  if(rm==0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,HIGH);
  }
  if(rm>0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
  }
  else if(rm<0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,HIGH);
  }
  if(lm>254) lm=254;                
  if(lm<-254) lm=-254;
  if(rm>254) rm=254;
  if(rm<-254) rm=-254;
  
  analogWrite(ena,abs(rm));         
  analogWrite(enb,abs(lm));         
  
}
