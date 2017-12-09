#include <LiquidCrystal.h>
#include <DS1302.h>

#define out 13
#define normal A0
#define quick A1
#define other A2

const int rs = 5, en = 6, d4 = 7, d5 = 8, d6 = 9, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

DS1302 rtc(2, 3, 4);

int normalState;
int quickState;
int otherState;
//for counting
int aumentarState;
int lastaumentarState;
int disminuirState;
int lastDisminuirState;

int owoState = false;
bool OwO = true;
bool UWU = false;

int ledState = LOW;
int ledState2 = LOW;

unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;        
        
long interval = 250;
long interval2 = 500;           
           
Time t;
void setup() {
  // set the digital pin as output:
  pinMode(out, OUTPUT);
  pinMode(quick, INPUT_PULLUP);
  pinMode(normal, INPUT_PULLUP);
  pinMode(other, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  lcd.begin(16, 2);
  digitalWrite(11, 1);
  rtc.halt(false);
  rtc.writeProtect(true);
  // Setup Serial connection
  Serial.begin(9600);
}
void losbotoneslaputamadreUwU(){
  normalState = digitalRead(normal);
  quickState = digitalRead(quick);
  otherState = digitalRead(other);
  
  if(normalState == 0 && quickState == 1 && otherState == 1){
    OwO = true;
    }
  else if(normalState == 1 && quickState == 0 && otherState == 1){
    OwO = false;
    UWU = false;
    }
   else if(normalState == 1 && quickState == 1 && otherState == 0){
    UWU = true;
    rtc.writeProtect(false);
    while(UWU){
//-----------------------------------WHILE----------------------------------------------------!


  //aumentarCount
  aumentarState = digitalRead(normal);
  disminuirState = digitalRead(quick);
  if (aumentarState != lastaumentarState) {
    //delay(90);//delay
    if (aumentarState == LOW) {
      //here the add one 
      }
    //delay(50);
  }
    lastaumentarState = aumentarState;
    
 if (disminuirState != lastDisminuirState) {
    //delay(90);
    if (disminuirState == LOW) { 
      //here the substract one
      }
    //delay(50);
  }
    lastDisminuirState = disminuirState;



//------------------------------------ENDOFWHILE----------------------------------------------!      
      }
    }
  }

    
void milis(){
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(out, ledState);
  }
  }


void showthefuckingtime(){

   unsigned long currentMillis2 = millis();

  if (currentMillis2 - previousMillis2 >= interval2) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis2;

    // if the LED is off turn it on and vice-versa:
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }

    if(ledState2 == HIGH){
  lcd.setCursor(4, 0);
  lcd.print(rtc.getTimeStr());
  

  lcd.setCursor(3, 1);
  lcd.print(rtc.getDateStr());
  t = rtc.getTime();
  if(OwO){
    if(t.sec == 00){
      if(owoState == false){
        digitalWrite(out, 1);
        owoState = true;
      }else{
        digitalWrite(out, 0);
        owoState = false;
        }
      }
//  }else{
//    milis();
//  }

  }
 }
}
}
 

  
void loop() {
  losbotoneslaputamadreUwU();
  if(OwO == false){
    milis();
    }
  
  showthefuckingtime();
}

