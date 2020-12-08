int ledPin = 32;
int button1 = 36;
int button2 = 35;
int button3 = 34;
int button4 = 33;
bool buttonState = LOW;
bool lastButtonState = LOW;
bool buttonState2 = LOW;
bool lastButtonState2 = LOW;
bool buttonState3 = LOW;
bool lastButtonState3 = LOW;
bool buttonState4 = LOW;
bool lastButtonState4 = LOW;
int potVal = 0;
int lastPotVal = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  Serial.begin(9600);

}


void loop() {
  midiSet();
  midiSet2();
  midiSet3();
  midiSet4();
  checkPot();

}

void midiSet() {
  lastButtonState = buttonState; // Turns off any extra notes that may be on
  buttonState = digitalRead(button1); // Will read if button1 is pressed or not
  if (lastButtonState == LOW and buttonState == HIGH) { // If button1 is pressed and the others are not, just play the note that's associated with button1
    usbMIDI.sendNoteOn(60, 127, 1); //that note is C
    digitalWrite(ledPin, HIGH); // Turn on the LED 
    delay(5); // When you release the button1, delay by 5 miliseconds to avoid extra noise
  } else if (lastButtonState == HIGH and buttonState == LOW) { // If there is another button pressed and button1 is not, don't play C
    usbMIDI.sendNoteOff(60, 0, 1); // Don't play Middle C
    digitalWrite(ledPin, LOW); // Turn off the LED
    delay(5); // Delay by 5 miliseconds to avoid any extra stuff
  }
}

void midiSet2() {
  lastButtonState2 = buttonState2;
  buttonState2 = digitalRead(button2);
  if (lastButtonState2 == LOW and buttonState2 == HIGH) {
    usbMIDI.sendNoteOn(64, 127, 1);
    digitalWrite(ledPin, HIGH);
    delay(5);
  } else if (lastButtonState2 == HIGH and buttonState2 == LOW) {
    usbMIDI.sendNoteOff(64, 0, 1);
    digitalWrite(ledPin, LOW);
    delay(5);
  }
}


void midiSet3() {
  lastButtonState3 = buttonState3;
  buttonState3 = digitalRead(button3);
  if (lastButtonState3 == LOW and buttonState3 == HIGH) {
    usbMIDI.sendNoteOn(67, 127, 1);
    digitalWrite(ledPin, HIGH);
    delay(5);
  } else if (lastButtonState3 == HIGH and buttonState3 == LOW) {
    usbMIDI.sendNoteOff(67, 0, 1);
    digitalWrite(ledPin, LOW);
    delay(5);
  }
}


void midiSet4() {
  lastButtonState4 = buttonState4;
  buttonState4 = digitalRead(button4);
  if (lastButtonState4 == LOW and buttonState4 == HIGH) {
    usbMIDI.sendNoteOn(71, 127, 1);
    digitalWrite(ledPin, HIGH);
    delay(5);
  } else if (lastButtonState4 == HIGH and buttonState4 == LOW) {
    usbMIDI.sendNoteOff(71, 0, 1);
    digitalWrite(ledPin, LOW);
    delay(5);
  }
}

void checkPot() { //Check if the potVal is not 10. If it's not, record the information
  usbMIDI.read();

  lastPotVal = potVal;
  potVal = map(analogRead(A12), 0, 1023, 10, 20);

  if(potVal != lastPotVal) {
    Serial.println(potVal);
  }
}
