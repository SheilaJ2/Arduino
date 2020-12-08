int ledPin = 32;
int ledPin2 = 30;
int ledPin3 = 28;
int ledPin4 = 26;
int button1 = 34;
int button2 = 33;
int button3 = 35;
int button4 = 36;
int potValue = 0;
int toggle = 37;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(toggle, INPUT);
}

void loop() {
  if (digitalRead(toggle) == HIGH) {
    arpeggioMode();
  } else {
    keyboardMode();
  }
}

void checkButton1() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button1) == HIGH) {
    usbMIDI.sendNoteOn(60, 127, 1);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    usbMIDI.sendNoteOff(60, 0, 1);
    delay(500);
  }
}

void checkButton2 () {
  if (digitalRead(button2) == HIGH) {
    usbMIDI.sendNoteOn(64, 127, 1);
    digitalWrite(ledPin2, HIGH);
    delay(500);
    digitalWrite(ledPin2, LOW);
    usbMIDI.sendNoteOff(64, 0, 1);
    delay(500);
  }
}


void checkButton3() {
  if (digitalRead(button3) == HIGH) {
    usbMIDI.sendNoteOn(67, 127, 1);
    digitalWrite(ledPin3, HIGH);
    delay(500);
    digitalWrite(ledPin3, LOW);
    usbMIDI.sendNoteOff(67, 0, 1);
    delay(500);
  }
}

void checkButton4() {
  if (digitalRead(button4) == HIGH) {
    usbMIDI.sendNoteOn(71, 127, 1);
    digitalWrite(ledPin4, HIGH);
    delay(500);
    digitalWrite(ledPin4, LOW);
    usbMIDI.sendNoteOff(71, 0, 1);
    delay(500);
  }
}

void keyboardMode() {
  checkButton1();
  checkButton2();
  checkButton3();
  checkButton4();
}

void arpeggioMode() {
  if (digitalRead(button1) == HIGH) {
    arpeggio(60);
  }
  if (digitalRead(button2) == HIGH) {
    arpeggio(64);
  }
  if (digitalRead(button3) == HIGH) {
    arpeggio(67);
  }
  if (digitalRead(button4) == HIGH) {
    arpeggio(71);
  }
}


void arpeggio(int note) {
  potValue = analogRead(A12);


  usbMIDI.sendNoteOn(note, 127, 1);
  delay(potValue);
  usbMIDI.sendNoteOff(note, 0, 1);

  usbMIDI.sendNoteOn(note + 4, 127, 1);
  delay(potValue);
  usbMIDI.sendNoteOff(note, 0, 1);

  usbMIDI.sendNoteOn(note + 7, 127, 1);
  delay(potValue);
  usbMIDI.sendNoteOff(note, 0, 1);

  usbMIDI.sendNoteOn(note + 11, 127, 1);
  delay(potValue);
  usbMIDI.sendNoteOff(note, 0, 1);
}
