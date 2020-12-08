int drumLeds[4] = {5, 7, 10, 12} ;
int channelLeds[3] = {20, 17, 14};
int drumButtons[4] = {28, 29, 30, 31};


int channelChangeButton = 32;
int toggle = 25;



int ledOn = 39;

int totalDrumLeds = 4;
int totalChannelPins = 3;
int totalDrumButtons = 4;
int totalSwitchOns = 4;


int currentChannel = 0;
int channelDisplayed = 0;
unsigned long lastStep = 0;
int currentStep = 0;
bool buttonState2 = LOW;
bool lastButtonState2 = LOW;


bool lastButtonState[4] = {LOW, LOW, LOW, LOW};
bool buttonState[4] = {LOW, LOW, LOW, LOW};
bool switchedOn[3][4] = {
  {LOW, HIGH, LOW, HIGH},
  {LOW, HIGH, HIGH, HIGH },
  {LOW, LOW, LOW, HIGH}
};


int melodicVals[4] = {0, 0, 0, 0};
int pot5 = 0;
int tempo = 0; //A19


int midiNotes[4] = {0, 0, 0, 0};
int midiDrumNotes[3] = {60, 64, 67};
int melodicSequencePots[4] = {A14, A15, A16, A17};
int turnOn = 0;


void setup () {
  for (int i = 0; i < totalDrumLeds; i++) {
    pinMode(drumLeds[i], OUTPUT);
  }
  for (int i = 0; i < totalChannelPins; i++) {
    pinMode(channelLeds[i], OUTPUT);
  }
  pinMode(channelChangeButton, INPUT);
  pinMode(toggle, INPUT);
  for (int i = 0; i < totalDrumButtons; i++) {
    pinMode(drumButtons[i], INPUT);
  }
  pinMode(ledOn, OUTPUT);
  Serial.begin(9600);
}


void loop () {
  if (digitalRead(toggle) == HIGH) {

    digitalWrite(ledOn, HIGH);
    checkDrumButtons();
    checkChannelButton();

    drumSequence();

    updateDrumLeds();


  } else {
    turnOff();
  }
}



void turnOff() {
  digitalWrite(ledOn, LOW);

  for (int i = 0; i < totalDrumLeds; i++) {
    digitalWrite(drumLeds[i], LOW);
  }
  for (int i = 0; i < totalChannelPins; i++) {
    digitalWrite(channelLeds[i], LOW);
  }
}


void checkDrumButtons() {
  for (int i = 0; i < totalDrumButtons; i++) {
    lastButtonState[i] = buttonState[i];
    buttonState[i] = digitalRead(drumButtons[i]);
  }
  for (int i = 0; i < totalSwitchOns; i++) {
    if (lastButtonState[i] == LOW && buttonState[i] == HIGH) {
      switchedOn[channelDisplayed][i] = !switchedOn[channelDisplayed][i]; // this means: if switchedOn is true then set it to false, if switchedOn is false then set it to true
      delay(5);
      Serial.println(i);
    } else if (lastButtonState[i] == HIGH && buttonState[i] == LOW) {
      delay(5);
    }
  }
}




void updateDrumLeds() {
  for (int i = 0; i < totalDrumLeds; i++) {

    if (switchedOn[channelDisplayed][i] == true or i == currentStep)  {
      digitalWrite(drumLeds[i], HIGH);
    } else {
      digitalWrite(drumLeds[i], LOW);
    }
  }
}


void checkChannelButton() {
  lastButtonState2 = buttonState2;
  buttonState2 = digitalRead(channelChangeButton);
  if (lastButtonState2 == LOW and buttonState2 == HIGH) {
    updateChannelLeds();
    delay(5);
  } else if (lastButtonState2 == HIGH and buttonState2 == LOW) {
    delay(5);
  }
}



void updateChannelLeds() {
  channelDisplayed++;
  if (channelDisplayed == 3) {
    channelDisplayed = 0;
  }

  for (int j = 0; j < totalChannelPins; j++) {
    if (j == channelDisplayed) {
      digitalWrite(channelLeds[j], HIGH);
    } else {
      digitalWrite(channelLeds[j], LOW);
    }
  }
}




void drumSequence() {
  pot5 = analogRead(A19);
  tempo = map(pot5, 0, 1023, 100, 1000);

  if (millis() > lastStep + tempo) {
    lastStep = millis();

    for (int i = 0; i < 3; i++) {
      usbMIDI.sendNoteOff(midiDrumNotes[i], 0, 1);
    }

    usbMIDI.sendNoteOff(midiNotes[currentStep], 0, 1);

    countUp();


    melodicVals[currentStep] = analogRead(melodicSequencePots[currentStep]);
    midiNotes[currentStep] = map(melodicVals[currentStep], 0, 1023, 60, 72);

    //Turn off the current melodic note.

    for (int i = 0; i < 3; i++) {
      if (switchedOn[i][currentStep] == HIGH) {
        usbMIDI.sendNoteOn(midiDrumNotes[i], 127, 1);
      }
    }

    melodicVals[currentStep] = analogRead(melodicSequencePots[currentStep]);
    midiNotes[currentStep] = map(melodicVals[currentStep], 0, 1023, 60, 72);

    usbMIDI.sendNoteOn(midiNotes[currentStep], 127, 1);
    //turn on current melodic note
  }
}

void countUp() {

  currentStep++;
  if (currentStep == totalDrumLeds) {
    currentStep = 0;

  }
}
