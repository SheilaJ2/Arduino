int ledPins[4] = {32, 30, 28, 26};
int totalLeds = 4;
int potVal = 0;
int buttonPin1 = 33;
int buttonPin2 = 34;
int toggle = 29;


void setup() {
  for (int i = 0; i < totalLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(toggle, INPUT);

}

void loop() {
  potVal = analogRead(A12);

  if (digitalRead(buttonPin2) == HIGH) {
    turnOnLeds();
    delay(potVal);
    turnOffLeds();
    delay(potVal);
  }

  if (digitalRead(toggle) == HIGH) {
    blinkLeds();
  } else {
    blinkLedsBackwards();
  }
}



void blinkLeds() {

  if (digitalRead(buttonPin1) == HIGH) {
    for (int i = 0; i < totalLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(potVal);
      digitalWrite(ledPins[i], LOW);
      delay(potVal);
    }
  }
}

void blinkLedsBackwards() {
  if (digitalRead(buttonPin1) == HIGH) {
    for (int i = 3; i > -1; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(potVal);
      digitalWrite(ledPins[i], LOW);
      delay(potVal);
    }
  }
}

void turnOnLeds() {
  for (int i = 0; i < totalLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}


void turnOffLeds() {
  for (int i = 0; i < totalLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
