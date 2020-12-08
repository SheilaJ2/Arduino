int ledPin = 12;
int ledPin2 = 10;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  blinkLed();

}

void blinkLed() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);

  digitalWrite(ledPin2, HIGH);
  delay(500);
  digitalWrite(ledPin2, LOW);
  delay(500);
}
