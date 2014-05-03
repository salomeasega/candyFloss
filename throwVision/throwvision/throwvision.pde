import spacebrew.*;
import processing.serial.*;


String server= "sandbox.spacebrew.cc"; //connecting to the server
String name ="throwvision"; 
String description ="This is a client that connects to incomming input from a url";

int colorChange = 2;
boolean previousValue = false;



Spacebrew sb;
Serial myPort;

void setup() {
  size (600, 600);

  // instantiate the spacebrewConnection variable
  sb = new Spacebrew( this );

  // declare your subscribers
  sb.addSubscribe( "sway", "boolean" );
  sb.addSubscribe( "shakeIt", "boolean" );


  // connect to spacebre
  sb.connect(server, name, description );

  myPort = new Serial(this, Serial.list()[1], 9600); 
  myPort.bufferUntil('\n');
  //  println(Serial.list());
}

void draw() {
  if (sb.connected()) {
    background(0);
    //print client name to screen
    fill(255);
    //title
    textSize (30); 
    textAlign(CENTER);
    text ("THROW VISION", width/2, height/2); 
    //print current value to screen
    textSize(10);
    textAlign(LEFT);
    text("Connected as: " + name, width/2, 25);
    text("boolean: " + colorChange, 25, 25);
  }
  else {
    text("Not Connected", 25, 25);
  }
}

void onBooleanMessage( String name, boolean value ) {
  println("got bool message " + name + " : " + value); 
  //  if (name == "sway" && value == true) {
  //    println("Swaying!!!!");
  //    println("got bool message " + name + " : " + value); 
  //    myPort.write(1);  
  //    if (value != previousValue) {
  //      myPort.write(1);  
  //      previousValue = value;
  //      println("sway: 1");
  //    }
  //  }
  
  if (name.equals("sway") && value == true) {
    println("I'm Swaying bitches!!!!"); 
    if (value != previousValue) {
      myPort.write(1);  
      previousValue = value;
      println("sway: 1");
    }
  }
  else if (name.equals("shakeIt") && value == true) {
    println("I'm shaking");
    if (value != previousValue) {
      myPort.write(2);
      println("I'm writing bitches!!");
      previousValue = value;
      //        println("shakeIt: 1");
    }
  }
  else if (value == false) {
    if (value != previousValue) {
      myPort.write(0);  
      previousValue = value;
      //        println("shakeIt: 1");
    }
    //        println("sway: 0");
    //        println("shakeIt: 0");
  }
}

//  // check value of shake it
//  if (name == "shakeIt") {
//    if (value == true) {
//      //if the value has changed write to Serial
//      if (value != previousValue) {
//        myPort.write(2);  
//        // change previous value to value so we know when the boolean has changed. we only want to write to the Serial port when there is a change
//        previousValue = value;
//        println("shakeIt: 1");
//      }
//    } 
//    else {
//      if (value != previousValue) {
//        myPort.write(0);
//
//        previousValue = value;
//        println("shakeIt: 0");
//      }
//    }
//  }
//}

