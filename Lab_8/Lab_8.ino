int ledPin[4] = {12, 24, 26, 28};
int buttonPin[4] = {32, 31, 30, 29};
int totalLeds = 4;
int totalButtons = 4;
int totalSwitchOn = 4;
int totalButtonPins = 4;
int midiNotes[4] = {0, 0, 0, 0};
int tempo = 0;
int pot = 0;
unsigned long lastStep = 0;
int currentStep = 0;
int totalSteps = 4;
int toggle = 35;

bool lastButtonState[4] = {LOW, LOW, LOW, LOW};
bool buttonState[4] = {LOW, LOW, LOW, LOW};
bool switchedOn[4] = {false, false, false, false}; // whyy :/ . ig so it doesn't do anything unless we say so. Unless we make it true aka HIGH. False also means LOW

void setup() {
  for (int i = 0; i < totalLeds; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
  for (int i = 0; i < totalButtons; i++) {
    pinMode(buttonPin[i], INPUT);
  }
  pinMode(toggle, INPUT);
  Serial.begin(9600);
}

void loop() {

  checkButtons();
  updateLeds();
  if (digitalRead(toggle) == HIGH) {
    sequenceForwards();
  } else {
    sequenceBackwards();
  }
}

void checkButtons() {
  for (int i = 0; i < totalButtons; i++) {
    lastButtonState[i] = buttonState[i];
    buttonState[i] = digitalRead(buttonPin[i]);
  }
  for (int i = 0; i < totalSwitchOn; i++) {

    if (lastButtonState[i] == LOW && buttonState[i] == HIGH) {
      switchedOn[i] = !switchedOn[i]; // this means: if switchedOn is true then set it to false, if switchedOn is false then set it to true
      delay(5);
    } else if (lastButtonState[i] == HIGH && buttonState[i] == LOW) {
      delay(5);
    }
  }
}


void updateLeds() {
  for (int i = 0; i < totalLeds; i++) {

    if (switchedOn[i] == true or i == currentStep)  {
      digitalWrite(ledPin[i], HIGH);
    } else {
      digitalWrite(ledPin[i], LOW);
    }
  }
}



void sequenceForwards() {
  pot = analogRead(A14);
  tempo = map(pot, 0, 1023, 100, 1000);


  if (millis() >= lastStep + tempo) {
    lastStep = millis();
    usbMIDI.sendNoteOff(midiNotes[currentStep], 0, 1);

    countUp();

    if (switchedOn[currentStep] == HIGH) { //this also means true. so If it's true that switchedOn is false.

      usbMIDI.sendNoteOn(midiNotes[currentStep], 127, 1);
      Serial.println(currentStep);

      usbMIDI.sendNoteOff(midiNotes[currentStep], 0, 1);
    } else {
      usbMIDI.sendNoteOff(midiNotes[currentStep], 0, 1);
    }
  }
}

void sequenceBackwards() {

  tempo = analogRead(A14);


  if (millis() >= lastStep + tempo) {
    lastStep = millis();
    usbMIDI.sendNoteOff(midiNotes[currentStep], 0, 1);

    countDown();

    if (switchedOn[currentStep] == HIGH) {

      usbMIDI.sendNoteOn(midiNotes[currentStep], 127, 1);
      Serial.println(currentStep);

      usbMIDI.sendNoteOff(midiNotes[currentStep], 0, 1);
    } else {
      usbMIDI.sendNoteOff(midiNotes[currentStep], 0, 1);
    }
  }
}

void countUp() {

  currentStep++;
  if (currentStep == totalLeds) {
    currentStep = 0;

  }
}

void countDown() {

  currentStep--;
  if (currentStep < 0) {
    currentStep = totalLeds - 1;
  }
}
