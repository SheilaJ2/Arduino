int ledPins[4] = {32, 30, 28, 26};
int totalLeds = 4;
int octave = 24;
int toggle2 = 29;
int toggle = 25;
int notePotVals[4] = {0, 0, 0, 0};
int pot5 = 0;
int pot5Mapped = 0;
int MidiNotes[4] = {0, 0, 0, 0};
int potPins[4] = {A17, A16, A15, A14};
int turnOn = 0;
int backwards = 0;

void setup() {
  for (int i = 0; i < totalLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(octave, INPUT);
  pinMode(toggle2, INPUT);
  pinMode(toggle, INPUT);
}

void loop() {
  pot5 = analogRead(A12);
  pot5Mapped = map(pot5, 0, 1023, 100, 1000);
  turnOn = digitalRead(toggle2);
  backwards = digitalRead(toggle);

  if (turnOn == HIGH and backwards == LOW) {
  sequenceForward();
  } else if (turnOn == HIGH and backwards == HIGH) {
  sequenceBackwards();
  }
}





void sequenceForward() {

  if (digitalRead(octave) == HIGH) {
    for (int i = 0; i < totalLeds; i++) {
      notePotVals[i] = analogRead(potPins[i]);
      MidiNotes[i] = map(notePotVals[i], 0, 1023, 60, 72);

      usbMIDI.sendNoteOn(MidiNotes[i] + 12, 127, 1);
      digitalWrite(ledPins[i], HIGH);
      delay(pot5Mapped);
      usbMIDI.sendNoteOff(MidiNotes[i] + 12, 0, 1);
      digitalWrite(ledPins[i], LOW);
      delay(pot5Mapped);
    }

  } else if (digitalRead(octave) == LOW) {
    for (int i = 0; i < totalLeds; i++) {
      notePotVals[i] = analogRead(potPins[i]);
      MidiNotes[i] = map(notePotVals[i], 0, 1023, 60, 72);

      usbMIDI.sendNoteOn(MidiNotes[i], 127, 1);
      digitalWrite(ledPins[i], HIGH);
      delay(pot5Mapped);
      usbMIDI.sendNoteOff(MidiNotes[i], 0, 1);
      digitalWrite(ledPins[i], LOW);
      delay(pot5Mapped);
    }
  }
}


void sequenceBackwards() {

  if (digitalRead(octave) == HIGH) {
    for (int i = 3; i > -1; i--) {
      notePotVals[i] = analogRead(potPins[i]);
      MidiNotes[i] = map(notePotVals[i], 0, 1023, 60, 72);

      usbMIDI.sendNoteOn(MidiNotes[i] + 12, 127, 1);
      digitalWrite(ledPins[i], HIGH);
      delay(pot5Mapped);
      usbMIDI.sendNoteOff(MidiNotes[i] + 12, 0, 1);
      digitalWrite(ledPins[i], LOW);
      delay(pot5Mapped);
    } //make sure you always declare something before you include another if statement. Because if you don't, it'll only check the first one

  } else if (digitalRead(octave) == LOW) {
    for (int i = 3; i > -1; i--) {
      notePotVals[i] = analogRead(potPins[i]);
      MidiNotes[i] = map(notePotVals[i], 0, 1023, 60, 72);

      usbMIDI.sendNoteOn(MidiNotes[i], 127, 1);
      digitalWrite(ledPins[i], HIGH);
      delay(pot5Mapped);
      usbMIDI.sendNoteOff(MidiNotes[i], 0, 1);
      digitalWrite(ledPins[i], LOW);
      delay(pot5Mapped);
    }
  }
}
