
// Code used to Display Lesson Number on the LED Matrix of the Uno R4 Board
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
String lesson = "14";


int ledPin = 11; // Define the pin for the LED
int brightness = 0;   // Variable to store the brightness value



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

  
  Serial.begin(9600); // Start serial communication
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

  

void loop() {
  int brightness; // Variable to store the brightness value
  
  // Ask the user to input a value between 1 and 10
  Serial.println("Enter LED brightness value (1-10, 1 is LED Off, 0 to exit):");
  while (!Serial.available()); // Wait for user input
  int userInput = Serial.parseInt(); // Read user input
  Serial.print("Your number is: ");
  Serial.println(userInput);

  // Check if the input is within the valid range
  if (userInput >= 0 && userInput <= 10) {
    // Map the user input to a brightness value between 0 and 255
    brightness = pow(userInput,2)-1;

    // Set the LED brightness using PWM
    analogWrite(ledPin, brightness);
    
    // If the input is 0, end the program
    if (userInput == 0) {
      Serial.println("Program ended.");
      while (true) {} // Loop indefinitely1
    }
  } else {
    Serial.println("Invalid input. Please enter a value between 0 and 10. 0 Ends Program");
  }
}
