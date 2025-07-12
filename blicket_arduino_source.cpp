#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Digital IO pin connected to the button. This will be driven with a
// pull-up resistor so the switch pulls the pin to ground momentarily.
// On a high -> low transition the button press logic will execute.
#define BUTTON_PIN_1   7
#define BUTTON_PIN_2   8
#define BUTTON_PIN_3   9
#define BUTTON_PIN_4   10
#define BUTTON_PIN_5   14
#define BUTTON_PIN_6   15


#define PIXEL_PIN_1    11  // Digital IO pin connected to the NeoPixels.
#define PIXEL_PIN_2    12  // Digital IO pin connected to the NeoPixels.
#define PIXEL_PIN_3    13  // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT    26  // Number of NeoPixels

#define remote_1 3 //A
#define remote_2 5 //B

#define remote_3 4 //C
#define remote_4 2 //D
#define remote_5 6 //VT

#define buzz 1
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip1(PIXEL_COUNT, PIXEL_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(PIXEL_COUNT, PIXEL_PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(PIXEL_COUNT, PIXEL_PIN_3, NEO_GRB + NEO_KHZ800);

// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

void setup() {
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  pinMode(BUTTON_PIN_5, INPUT_PULLUP);
  pinMode(BUTTON_PIN_6, INPUT_PULLUP);
  
  pinMode(remote_1, INPUT_PULLUP);
  pinMode(remote_2, INPUT_PULLUP);
  pinMode(remote_3, INPUT_PULLUP);
  pinMode(remote_4, INPUT_PULLUP);
  pinMode(remote_2, INPUT_PULLUP);

  pinMode(buzz, OUTPUT);

  strip1.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip1.show();  // Initialize all pixels to 'off'
  
  strip2.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip2.show();  // Initialize all pixels to 'off'
  
  strip3.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip3.show();  // Initialize all pixels to 'off'
}

void loop() {
    
    
    boolean sw_state0 = digitalRead(BUTTON_PIN_1);
    boolean sw_state1 = digitalRead(BUTTON_PIN_2);
    boolean sw_state2 = digitalRead(BUTTON_PIN_3);
    boolean sw_state3 = digitalRead(BUTTON_PIN_4);
    boolean sw_state4 = digitalRead(BUTTON_PIN_5);
    boolean sw_state5 = digitalRead(BUTTON_PIN_6);
    


    boolean A = digitalRead(remote_1);
    boolean B = digitalRead(remote_2);
    boolean C = digitalRead(remote_3);
    boolean D = digitalRead(remote_4);
    boolean E = digitalRead(remote_5);

    delay(20);

  if (A==HIGH){
      if((sw_state0 == LOW)||(sw_state1 == LOW)||(sw_state2 == LOW)||(sw_state3 == LOW)||(sw_state4 == LOW)||(sw_state5 == LOW)) {
        delay(20);
        colorWipe1(strip1.Color(255,   255,   255), 1);    // white
        colorWipe2(strip2.Color(255,   255,   255), 1);    // white
        colorWipe3(strip3.Color(255,   255,   255), 1);    // white
  
      }
      else{
          colorWipe1(strip1.Color(0,   0,   0), 1);    // blank
          colorWipe2(strip2.Color(0,   0,   0), 1);    // blank
          colorWipe3(strip3.Color(0,   0,   0), 1);    // blank
      }
  }
    else if(B==HIGH){
      if((sw_state0 == LOW)||(sw_state1 == LOW)||(sw_state2 == LOW)||(sw_state3 == LOW)||(sw_state4 == LOW)||(sw_state5 == LOW)) {
        delay(20);
        colorWipe1(strip1.Color(255,   0,   0), 1);    // Red
        colorWipe2(strip2.Color(255,   0,   0), 1);    // Red
        colorWipe3(strip3.Color(255,   0,   0), 1);    // Red
        tone(buzz, 22000);
        delay(10);
        // noTone(buzz);//Sets the voltage to low and makes no noise
        delay(10);
      }
      else{
          colorWipe1(strip1.Color(0,   0,   0), 1);    // blank
          colorWipe2(strip2.Color(0,   0,   0), 1);    // blank
          colorWipe3(strip3.Color(0,   0,   0), 1);    // blank
          // noTone(buzz);//Sets the voltage to low and makes no noise
      }
    }

        else if(C==HIGH){
        if(E==HIGH) {
        delay(20);
        colorWipe1(strip1.Color(0,   0,   255), 1);    // blue
        colorWipe2(strip2.Color(0,   0,   255), 1);    // blue
        colorWipe3(strip3.Color(0,   0,   255), 1);    // blue
  
      }
      else{
          colorWipe1(strip1.Color(0,   0,   0), 1);    // blank
          colorWipe2(strip2.Color(0,   0,   0), 1);    // blank
          colorWipe3(strip3.Color(0,   0,   0), 1);    // blank
      }
    }

      else if(D==HIGH){

        delay(20);
          colorWipe1(strip1.Color(0,   0,   0), 1);    // blank
          colorWipe2(strip2.Color(0,   0,   0), 1);    // blank
          colorWipe3(strip3.Color(0,   0,   0), 1);    // blank
    }

      
}

void colorWipe1(uint32_t color, int wait) {
  for(int i=0; i<strip1.numPixels(); i++) { // For each pixel in strip...
    strip1.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip1.show();                          //  Update strip to match
    //delay(wait);                           //  Pause for a moment
  }
}

void colorWipe2(uint32_t color, int wait) {
  for(int i=0; i<strip1.numPixels(); i++) { // For each pixel in strip...
    strip2.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip2.show();                          //  Update strip to match
    //delay(wait);                           //  Pause for a moment
  }
}



void colorWipe3(uint32_t color, int wait) {
  for(int i=0; i<strip1.numPixels(); i++) { // For each pixel in strip...
    strip3.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip3.show();                          //  Update strip to match
    //delay(wait);                           //  Pause for a moment
  }
}


void colorWipeV0_1(uint32_t color, int wait) {
  for(int i=0; i<strip1.numPixels(); i++) { // For each pixel in strip...
    strip1.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip1.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void colorWipeV0_2(uint32_t color, int wait) {
  for(int i=0; i<strip1.numPixels(); i++) { // For each pixel in strip...
    strip2.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip2.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void colorWipeV0_3(uint32_t color, int wait) {
  for(int i=0; i<strip1.numPixels(); i++) { // For each pixel in strip...
    strip3.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip3.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}



