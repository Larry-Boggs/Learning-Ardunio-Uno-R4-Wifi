const int ledPins[] = {2, 3, 4, 5, 6}; // Pins connected to LEDs
int count = 0; // Counter variable


// Code used to Display Lesson Number on the LED Matrix of the Uno R4 Board
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

String message= "06";


void setup() {
  // Initialize LED pins as output
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
matrix.begin();//Start Matrix on Board

}

void loop() {

// Code used to Display Lesson on Uno R4 LED Matrix on Board
matrix.beginDraw();
matrix.textFont(Font_5x7);
matrix.beginText(0,1,255,0,0);
matrix.println(message);
matrix.endText();
matrix.endDraw();

  // Convert count to binary and display on LEDs

  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], bitRead(count, i));
  }
  
  delay(500); // Delay for visibility
  
  // Increment count, reset if it reaches 31
  count++;
  if (count > 31) {
    count = 0;
    delay(2000);
  }

  }
