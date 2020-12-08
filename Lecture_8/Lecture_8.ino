<Adafruit_NeoPixel.h>

Adafruit_NeoPixel neopixel = Adafruit_Neopixel(1, 32, NEO_RGB);

int colors[5][3] = { // 5 arrays each 3 long. the 3 holds the red, green, blue
  {255, 0, 0 }, //red
  {127, 127, 0 }, //yellow
  {0, 255, 0 }, //green
  {127, 0, 127 }, //pink
  {0, 127, 0 } //light blue
};



void setup() {
  neopixel.begin();
  neopixel.clear();
  neopixel.show();
  neopixel.setBrightness(40); //number between 0-255

}

void loop() {
  for (int i = 0; i < 5; i++) {

    // (ledNumber, red, green, blue)
    neopixel.setPixel(0, colors[i][0], colors[i][1], colors[i][2]);
    neopixel.show();
    delay(1000);
  }
}
