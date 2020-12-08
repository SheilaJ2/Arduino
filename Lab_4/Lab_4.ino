int ledPin = 32;
int ledPin2 = 30;
int ledPin3 = 28;
int ledPin4 = 26;
int toggle = 24;
int toggle2 = 29;
int pot1 = 0;
int pot2 = 0;
int pot3 = 0;
int pot4 = 0;
int pot5 = 0;
int pot5Mapped = 0;
int pot1Mapped = 0;
int pot2Mapped = 0;
int pot3Mapped = 0;
int pot4Mapped = 0;
int turnOn = 0;
int octave = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(toggle, INPUT);
  pinMode(toggle2, INPUT);

  // put your setup code here, to run once:

}

void loop() {
  pot5 = analogRead(A12);
  pot5Mapped = map(pot5, 0, 1023, 100, 1000);
  turnOn = digitalRead(toggle2);
  octave = digitalRead(toggle);

  
  if (turnOn == HIGH and octave == LOW) {
    blinkLed(pot1Mapped);
    blinkLed2(pot2Mapped);
    blinkLed3(pot3Mapped);
    blinkLed4(pot4Mapped);
  } else if (octave == HIGH and turnOn == HIGH) {
    blinkLed(pot1Mapped + 12);
    blinkLed2(pot2Mapped + 12);
    blinkLed3(pot3Mapped + 12);
    blinkLed4(pot4Mapped + 12);
  }

}
// put your main code here, to run repeatedly:

void  blinkLed(int note) {
  pot1 = analogRead(A17);
  pot1Mapped = map(pot1, 0, 1023, 60, 72);

  usbMIDI.sendNoteOn(note, 127, 1);
  digitalWrite(ledPin, HIGH);
  delay(pot5Mapped);
  usbMIDI.sendNoteOff(note, 0, 1);
  digitalWrite(ledPin, LOW);
  delay(pot5Mapped);
}

void  blinkLed2(int note) {
  pot2 = analogRead(A16);
  pot2Mapped = map(pot2, 0, 1023, 60, 72);

  usbMIDI.sendNoteOn(note, 127, 1);
  digitalWrite(ledPin2, HIGH) ;
  delay(pot5Mapped);
  usbMIDI.sendNoteOff(note, 0, 1);
  digitalWrite(ledPin2, LOW) ;
  delay(pot5Mapped);
}


void  blinkLed3(int note) {
  pot3 = analogRead(A15);
  pot3Mapped = map(pot3, 0, 1023, 60, 72);
  
  usbMIDI.sendNoteOn(note, 127, 1);
  digitalWrite(ledPin3, HIGH) ;
  delay(pot5Mapped);
  usbMIDI.sendNoteOff(note, 0, 1);
  digitalWrite(ledPin3, LOW) ;
  delay(pot5Mapped);
}


void  blinkLed4(int note) {
  pot4 = analogRead(A14);
  pot4Mapped = map(pot4, 0, 1023, 60, 72);
  
  usbMIDI.sendNoteOn(note, 127, 1);
  digitalWrite(ledPin4, HIGH) ;
  delay(pot5Mapped);
  usbMIDI.sendNoteOff(note, 0, 1);
  digitalWrite(ledPin4, LOW) ;
  delay(pot5Mapped);
}
