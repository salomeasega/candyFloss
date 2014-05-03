#include <Adafruit_NeoPixel.h>

#define PIN1 3
#define PIN2 5
#define PIN3 6
#define PIN4 9

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(15, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(15, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(15, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(15, PIN4, NEO_GRB + NEO_KHZ800);

int colorReading = 0;

void setup() {
  Serial.begin(9600); 
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
}

void loop() {

  if (Serial.available() > 0) {
    colorReading = Serial.read();

    if(colorReading ==0){
      colorWipe(strip1.Color(127, 127, 127), 10); 
      colorWipe(strip2.Color(127, 127, 127), 10); 
      colorWipe(strip3.Color(127, 127, 127), 10); 
      colorWipe(strip4.Color(127, 127, 127), 10); 
    }
    if(colorReading == 1){
      colorWipe(strip1.Color(0, 0, 127), 10); 
      colorWipe(strip2.Color(0, 0, 127), 10); 
      colorWipe(strip3.Color(0, 0, 127), 10); 
      colorWipe(strip4.Color(0, 0, 127), 10); 
    }
    if(colorReading == 2){
      colorWipe(strip1.Color(127, 0, 0), 10); 
      colorWipe(strip2.Color(127, 0, 0), 10); 
      colorWipe(strip3.Color(127, 0, 0), 10); 
      colorWipe(strip4.Color(127, 0, 0), 10); 
    }
  }







}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    delay(wait);
  }
  for(uint16_t i=0; i<strip2.numPixels(); i++) {
    strip2.setPixelColor(i, c);
    strip2.show();
    delay(wait);
  }
  for(uint16_t i=0; i<strip3.numPixels(); i++) {
    strip3.setPixelColor(i, c);
    strip3.show();
    delay(wait);
  }
  for(uint16_t i=0; i<strip4.numPixels(); i++) {
    strip4.setPixelColor(i, c);
    strip4.show();
    delay(wait);
  }
}


//Theatre-style crawling lights with rainbow effect
//void theaterChaseRainbow(uint8_t wait) {
//  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
//    for (int q=0; q < 3; q++) {
//      for (int i=0; i < strip.numPixels(); i=i+3) {
//        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
//      }
//      strip.show();
//
//      delay(wait);
//
//      for (int i=0; i < strip.numPixels(); i=i+3) {
//        strip.setPixelColor(i+q, 0);        //turn every third pixel off
//      }
//    }
//  }
//}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    return strip2.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    return strip3.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    return strip4.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    return strip2.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    return strip3.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    return strip4.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    return strip2.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    return strip3.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    return strip4.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}







