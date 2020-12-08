int tempo = 1000;

void setup() {
  neopixel.begin();
  neopixel.clear();
  neopixel.show();
}

void loop() {
  neopixel.setPixelColor(0, 255, 0, 0);
  neopixel.show();
  delay(tempo);

}
