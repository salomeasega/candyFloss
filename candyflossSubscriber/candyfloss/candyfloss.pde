//Spacebrew Collab 2014 Parsons the New School for Design 
// Candyfloss in Concert Susse Jensen and Salome Asega 

import spacebrew.*;
import processing.serial.*;

String server= "sandbox.spacebrew.cc"; //connecting to the server
String name ="candyfloss"; 
String description ="This is a client that connects to incomming input from a url";
int rotationVal = 500;
int colorVal = 500; 
Spacebrew sb;
Serial myPort; //seral port connetion 


void setup() {
  frameRate(240); 
  size (600, 600);

  // instantiate the spacebrewConnection variable
  sb = new Spacebrew( this );

  //add each thing you publish and subscribe to 
  sb.addSubscribe("rotation", "range"); 
  sb.addSubscribe("lightColor", "range");

  //connect! 
  sb.connect (server, name, description); 

  myPort = new Serial(this, Serial.list()[0], 9600); 
  myPort.bufferUntil('\n');
} 

void draw () { 
  background (203, 14, 160); 
  fill (255); 
  textSize (30); 
  textAlign(CENTER); 
  text ("candyfloss for all you candyhearts", width/2, height/2); 

  //  println("rotationRange = " + mappedR + " | ledRange = " + colorVal);

  // now make controls for rotation and color ranges
} 


void onRangeMessage (String name, int value) {


  if (name.equals("rotation")) {
    rotationVal = value;
  }
  if (name.equals("lightColor")) {
    colorVal = value;
  } 
  int mappedRotation = int(map(rotationVal, 0, 1023, 0, 180));
  int mappedColor = int(map(colorVal, 0, 1023, 0, 255)); 

  myPort.write(mappedRotation + "," + mappedColor+"\n");

  println(mappedRotation + "," + mappedColor);
} 

void serialEvent(Serial myPort)
{
  // read the serial buffer:
  String myString = myPort.readStringUntil('\n');
  println(myString);
}

