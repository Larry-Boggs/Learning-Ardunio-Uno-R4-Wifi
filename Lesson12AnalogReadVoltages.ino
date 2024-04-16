
// Code used to Display Lesson Number on the LED Matrix of the Uno R4 Board
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
String lesson = "12";


// Define Varibles for Lesson

int potPin = A1;
int potVal;
int br = 9600;
int waitT = 100;
float volts;
int redLED = 11;

void setup() {
  // put your setup code here, to run once:



  // Code used to Display Lesson on Uno R4 LED Matrix on Board
  matrix.beginDraw();
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 255, 0, 0);
  matrix.println(lesson);
  matrix.endText();
  matrix.endDraw();
  matrix.begin();  //Start Matrix on Board

  pinMode(potPin, INPUT);
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  volts=(5./1023)*potVal;
  Serial.print("pot:  ");
  Serial.print(potVal);
  Serial.print("Voltage:  ");
  Serial.println(volts);
  analogWrite(redLED,potVal);
  delay(waitT);
}