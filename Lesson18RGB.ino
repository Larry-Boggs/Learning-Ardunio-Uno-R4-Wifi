// Code used to Display Lesson Number on the LED Matrix of the Uno R4 Board
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
String lesson = "18";

int redPin=9;
int greenPin=10;
int bluePin=11;
int br=115200;




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

  
Serial.begin(br);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);

// Turn off the RGB LED initially
 turnOffLED();
 Serial.println("Enter a color (red, green, blue, cyan, magenta, yellow, orange, white, black ( to Exit):");
}


void loop() {
  // Check if data is available from the serial input
  if (Serial.available() > 0) {
    // Read the input string
    String input = Serial.readStringUntil('\n');
    
    // Remove any leading/trailing whitespace
    input.trim();
    
    // Convert input to lowercase
    input.toLowerCase();
    // Set the RGB LED based on the input color
    if (input == "red") {
      setColor(255, 0, 0);
      Serial.println("Your selected color is: red");
    } else if (input == "green") {
      setColor(0, 255, 0);
      Serial.println("Your selected color is: green");
    } else if (input == "blue") {
      setColor(0, 0, 255);
      Serial.println("Your selected color is: blue");
    } else if (input == "cyan") {
      setColor(0, 255, 255);
      Serial.println("Your selected color is: cyan");
    } else if (input == "magenta") {
      setColor(255, 0, 255);
      Serial.println("Your selected color is: magenta");
    } else if (input == "yellow") {
      setColor(255, 255, 0);
      Serial.println("Your selected color is: yellow");
    } else if (input == "orange") {
      setColor(255, 165, 0);
      Serial.println("Your selected color is: orange");
    } else if (input == "white") {
      setColor(255, 255, 255);
      Serial.println("Your selected color is: white");
    } else if (input == "black") {
      turnOffLED();
      Serial.println("LED turned off. Exiting program.");
      while (true); // Exit the loop to stop the program
    } else {
      Serial.println("Invalid color. Please enter a valid color (red, green, blue, cyan, magenta, yellow, orange, white, black (to Exit)):");
    }
    
    // Prompt for the next color input
    Serial.println("Enter a color (red, green, blue, cyan, magenta, yellow, orange, white, black(to Exit)):");
  }
}

void setColor(int red, int green, int blue) {
  // Set the RGB LED to the specified color
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void turnOffLED() {
  // Turn off the RGB LED
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}


