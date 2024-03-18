
// Code used to Display Lesson Number on the LED Matrix of the Uno R4 Board
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

String lesson= "08";


// Define Varibles for Lesson
int grnPin=9;
int redPin=8;

int blinkCnt;
int grnLEDcnt=5;
int grnBlinkSpeed=120;
int redLEDcnt=10;
int redBlinkSpeed=250;
int btwLEDdelay=500;
int loopDelay=1000;

void setup() {
  // put your setup code here, to run once:

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
    delay(grnBlinkSpeed);
    digitalWrite(grnPin,LOW);
    delay(grnBlinkSpeed);

  }
delay(btwLEDdelay);

 for (blinkCnt = 1; blinkCnt <= redLEDcnt;blinkCnt++) {
    digitalWrite(redPin, HIGH);
    delay(redBlinkSpeed);
    digitalWrite(redPin,LOW);
    delay(redBlinkSpeed);

  }
delay(loopDelay);

}
