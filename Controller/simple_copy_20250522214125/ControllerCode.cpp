// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library
#include <c:\Users\Ian\Documents\GitHub\CE-Capstone-Project\SharedCommunication\CommLibrary\Comm Library\src\main.cpp>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        1 //led ring pin
const int buttonPin = 12;  // the number of the pushbutton pin
const int buttonPin1 = 13;  // the number of the pushbutton pin
const int buttonPin2 = 14;  // the number of the pushbutton pin
const int buttonPin3 = 11;  // the number of the pushbutton pin
const int mosfetPin = 15;
const int id = 1;


#define NUMPIXELS 35 //NeoPixel ring size
int buttonState = digitalRead(buttonPin);
int buttonState1 = digitalRead(buttonPin1);
int buttonState2 = digitalRead(buttonPin2);
int buttonState3 = digitalRead(buttonPin3);
int buzzertimer;


// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  buttonState = digitalRead(buttonPin);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    // Set the GPIO pin as an output
  pinMode(mosfetPin, OUTPUT);
  // Start with the MOSFET off
  digitalWrite(mosfetPin, LOW); // or HIGH for a P-channel MOSFET
}

void loop() {
  
  pixels.clear(); // Set all pixel colors to 'off'

  if(1==1){
    buzzer(1);
    buzzertimer = 0;
  }
  if(buzzertimer == 150)
  {
  buzzer(0);
  }
  else
  {
    buzzertimer++;
  }

}

void buttons()
{
  while(1){
  if(buttonState == HIGH)
  {
      enum ButtonType {
    STAR = 1,
    SQUARE = 0,
    TRIANGLE = 0,
    HEXAGON = 0
  };

  }
  else if(buttonState1 == HIGH)
  {
      enum ButtonType {
    STAR = 0,
    SQUARE = 1,
    TRIANGLE = 0,
    HEXAGON = 0
  };
  }
  else if(buttonState2 == HIGH)
  {
      enum ButtonType {
    STAR = 0,
    SQUARE = 0,
    TRIANGLE = 1,
    HEXAGON = 0
  };
  }
  else if(buttonState3 == HIGH)
  {
    //Txmessage.buttonpress = HEXAGON;
  };
  }
  buttonState = digitalRead(buttonPin);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  }


void buzzer(int i)
{
  digitalWrite(mosfetPin, i); // or LOW for a P-channel MOSFET
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<3; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, c);    //turn every third pixel on
      }
      pixels.show();

      delay(wait);

      for (uint16_t i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

void score(uint8_t j)
{
for(int i=0; i<j; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 0, 150));
    pixels.show();
  }
}