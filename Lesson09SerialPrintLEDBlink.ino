
// Code used to Display Lesson Number on the LED Matrix of the Uno R4 Board
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

String lesson= "09";
String grnOn="Your Green LED is ON";
String grnOff="Your Green LED is OFF";
String redOn="Your Red LED is ON";
String redOff="Your Red LED is OFF";


// Define Varibles for Lesson
int grnPin=9;
int redPin=8;

int blinkCnt;
int grnLEDcnt=1;
int grnBlinkSpeed=1000;
int redLEDcnt=1;
int redBlinkSpeed=1000;
int btwLEDdelay=0;
int loopDelay=0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

// Code used to Display Lesson on Uno R4 LED Matrix on Board
matrix.beginDraw();
matrix.textFont(Font_5x7);
matrix.beginText(0,1,255,0,0);
matrix.println(lesson);
matrix.endText();
matrix.endDraw();
matrix.begin();//Start Matrix on Board

pinMode(grnPin,OUTPUT);
pinMode(redPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (blinkCnt = 1; blinkCnt <= grnLEDcnt;blinkCnt++) {
    digitalWrite(grnPin, HIGH);
    Serial.println(grnOn);
    delay(grnBlinkSpeed);
    digitalWrite(grnPin,LOW);
    Serial.println(grnOff);
    delay(grnBlinkSpeed);

  }
delay(btwLEDdelay);

 for (blinkCnt = 1; blinkCnt <= redLEDcnt;blinkCnt++) {
    digitalWrite(redPin, HIGH);
     Serial.println(redOn);
    delay(redBlinkSpeed);
    digitalWrite(redPin,LOW);
    Serial.println(redOff);

    delay(redBlinkSpeed);

  }
delay(loopDelay);

}
