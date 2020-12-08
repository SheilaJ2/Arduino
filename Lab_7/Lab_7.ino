#include <Adafruit_NeoPixel.h>

// replace the 32 below with whatever pin your Neopixel is connected to
Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(2, 32, NEO_RGB);

int tempo = 1000;
int pot1 = 0; //A17
int pot2 = 0; //A16
int pot3 = 0; //A15
int red = 0;
int green = 0;
int blue = 0;
int button1 = 30;
int ledPin = 28;

bool lastButtonState = LOW;
bool buttonState = LOW;
bool switchedOn = false;

void setup() {
  neopixel.begin();
  neopixel.clear();
  neopixel.show();
  pinMode(button1, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  pot1 = analogRead (A17);
  blue = map(pot1, 0, 1023, 0, 255);

  pot2 = analogRead(A16);
  green = map(pot2, 0, 1023, 0, 255);

  pot3 = analogRead(A15);
  red = map(pot3, 0, 1023, 0, 255);

  neopixel.setPixelColor(0, red, green, blue);
  neopixel.setPixelColor(1, green, blue, red);
  
  


  checkButton();
  updateLed();
}

void  checkButton()  {
  lastButtonState = buttonState;
  buttonState = digitalRead(button1);
  if (lastButtonState == LOW && buttonState == HIGH) {
    flipButtonState();
    delay(5);
  } else if (lastButtonState == HIGH && buttonState == LOW) {
    delay(5);
  }


}

void flipButtonState() {
  if (switchedOn == true) {
    switchedOn = false;
  } else if (switchedOn == false) {
    switchedOn = true;
  }
}

void updateLed() {
  if (switchedOn == true) {
    neopixel.show();
  } else {
    neopixel.setPixelColor(0, 0, 0, 0);
    neopixel.setPixelColor(1, 0, 0, 0);
    neopixel.show();
  }
}
