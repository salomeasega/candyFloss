#include <Servo.h> 

//where incoming data will be stored
int rotationVal;
int colorVal;

Servo hatServo;  // create servo object to control a servo  
int pos = 0;    // variable to store the servo position 

//RGB LED 
int redPin = 3;
int greenPin = 5;
int bluePin = 6; 

String readString;


void setup() 
{ 
  Serial.begin(9600);

  hatServo.attach(9);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

} 



void loop() {
  //Read incoming data via Serial connection

  if ( Serial.available() > 0) {

    char c = Serial.read(); //gets one byte from serial buffer

    if (c == '\n') {
      for (int i = 0; i < readString.length(); i++) {
        if (readString.substring(i, i+1) == ",") {
          String rot = readString.substring(0, i);
          String col = readString.substring(i+1);
          rotationVal = rot.toInt();
          colorVal = col.toInt();
          break;
        }
      }

      readString = "";
    } 
    else {
      readString += c; //makes the string readString
    }

  }

  //SERVO MOTOR
  hatServo.write(rotationVal);



  //RGB LED

  analogWrite(redPin, colorVal);
  analogWrite(greenPin, colorVal);
  analogWrite(bluePin, colorVal);


}





