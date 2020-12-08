int ledPins[4] = {32, 30, 28, 26};
int potPinArray[4] = {A17, A16, A15, A14};
int midiNotes[4] = {0, 0, 0, 0};
int pot5Mapped = 0;
int octave = 24;
int toggle = 25;
unsigned long lastStepTime = 0;
int currentStep = 0;
int totalSteps = 4;
int tempo = 0;
int value = 0;
int totalLeds = 4;
int pot1 = 0;
int tempoMapped = 0;




void setup() {
  Serial.begin(9600);
  for (int i = 0; i < totalLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(toggle, INPUT);
  pinMode(octave, INPUT);
}

void loop() {
  tempo = analogRead(A12);
  tempoMapped = map(tempo, 0 , 1023, 100, 1000);
  if (digitalRead(toggle) == HIGH) {
    sequenceForwards();
  } else {
    sequenceBackwards();
  }
}



void sequenceForwards() {
  if (digitalRead(octave) == LOW) {
    
    if (millis() >= lastStepTime + tempoMapped) {
      lastStepTime = millis();
      digitalWrite(ledPins[currentStep], LOW);
      usbMIDI.sendNoteOff(midiNotes[currentStep], 0, 1);

      countUp();


      pot1 = analogRead(potPinArray[currentStep]);
      midiNotes[currentStep] = map(pot1, 0, 1023, 60, 72);
      usbMIDI.sendNoteOn(midiNotes[currentStep], 127, 1);
      digitalWrite(ledPins[currentStep], HIGH);

      Serial.println(currentStep);
    }
  } else if (digitalRead(octave) == HIGH) {
    sequenceForwardsOctave();
    }
  }



void sequenceBackwards() {
  if (digitalRead(octave) == LOW) {

    if (millis() >= lastStepTime + tempoMapped) {
      lastStepTime = millis();
      digitalWrite(ledPins[currentStep], LOW);
      usbMIDI.sendNoteOff(midiNotes[currentStep], 0, 1);

      countDown();


      pot1 = analogRead(potPinArray[currentStep]);
      midiNotes[currentStep] = map(pot1, 0, 1023, 60, 72);
      usbMIDI.sendNoteOn(midiNotes[currentStep], 127, 1);
      digitalWrite(ledPins[currentStep], HIGH);

      Serial.println(currentStep);
    }
  } else if (digitalRead(octave) == HIGH) {
    sequenceBackWardsOctave(); {
    }
  }
}
void countUp() {

  currentStep++;
  if (currentStep == totalSteps) {
    currentStep = 0;
  }
}

void countDown() {

  currentStep--;
  if (currentStep < 0) {
    currentStep = totalSteps - 1;
  }
}

void sequenceForwardsOctave () {

  if (millis() >= lastStepTime + tempoMapped) {
    lastStepTime = millis();
    digitalWrite(ledPins[currentStep], LOW);
    usbMIDI.sendNoteOff(midiNotes[currentStep] + 12, 0, 1);

    countUp();


    pot1 = analogRead(potPinArray[currentStep]);
    midiNotes[currentStep] = map(pot1, 0, 1023, 60, 72);
    usbMIDI.sendNoteOn(midiNotes[currentStep] + 12, 127, 1);
    digitalWrite(ledPins[currentStep], HIGH);

    Serial.println(currentStep);
  }
}


void sequenceBackWardsOctave () {

  if (millis() >= lastStepTime + tempoMapped) {
    lastStepTime = millis();
    digitalWrite(ledPins[currentStep], LOW);
    usbMIDI.sendNoteOff(midiNotes[currentStep] + 12, 0, 1);

    countDown();


    pot1 = analogRead(potPinArray[currentStep]);
    midiNotes[currentStep] = map(pot1, 0, 1023, 60, 72);
    usbMIDI.sendNoteOn(midiNotes[currentStep] + 12, 127, 1);
    digitalWrite(ledPins[currentStep], HIGH);

    Serial.println(currentStep);
  }
}
