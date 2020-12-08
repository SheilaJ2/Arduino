int sequenceLedPins[4] = {12, 24, 26, 28};
int channelNumberLedPins[3] = {14, 16, 18}; //what channel we on
int buttonPin[4] = {32, 31, 30, 29};

int totalLeds = 4;
int totalLeds2 = 3;
int totalButtons = 4;
int totalSwitchOn = 4;
int totalButtonPins = 4;

int midiNotes[3] = {60, 64, 67};

int tempo = 0;
int pot = 0;
unsigned long lastStep = 0;

int currentStep = 0;
int totalSteps = 4;

int channelSwitchButton = 38;
int channelDisplayed = 0; //this variable is for the bool statements(switchedOn)
int channelButtonPin = 38;
int currentChannel = 0;

bool buttonState2 = LOW;
bool lastButtonState2 = LOW;


bool lastButtonState[4] = {LOW, LOW, LOW, LOW};
bool buttonState[4] = {LOW, LOW, LOW, LOW};
bool switchedOn[3][4] = {
  {LOW, HIGH, LOW, HIGH},
  {LOW, HIGH, HIGH, HIGH },
  {LOW, LOW, LOW, HIGH}
};

void setup() {
  for (int i = 0; i < totalLeds; i++) {
    pinMode(sequenceLedPins[i], OUTPUT);
  }
  for (int i = 0; i < totalButtons; i++) {
    pinMode(buttonPin[i], INPUT);
  }
  for (int i = 0; i < totalLeds2; i++) {
    pinMode(channelNumberLedPins[i], OUTPUT);
  }
  //  pinMode(toggle, INPUT);
  pinMode(channelButtonPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  checkButtons();
  updateSequenceLeds();

  checkButton2();

  sequenceForwards();
}


void checkButtons() {
  for (int i = 0; i < totalButtons; i++) {
    lastButtonState[i] = buttonState[i];
    buttonState[i] = digitalRead(buttonPin[i]);
  }
  for (int i = 0; i < totalSwitchOn; i++) {
    if (lastButtonState[i] == LOW && buttonState[i] == HIGH) {
      switchedOn[channelDisplayed][i] = !switchedOn[channelDisplayed][i]; // this means: if switchedOn is true then set it to false, if switchedOn is false then set it to true
      delay(5);
    } else if (lastButtonState[i] == HIGH && buttonState[i] == LOW) {
      delay(5);
    }
  }
}




void updateSequenceLeds() {
  for (int i = 0; i < totalLeds; i++) {

    if (switchedOn[channelDisplayed][i] == true or i == currentStep)  {
      digitalWrite(sequenceLedPins[i], HIGH);
    } else {
      digitalWrite(sequenceLedPins[i], LOW);
    }
  }
}


void checkButton2() {
  lastButtonState2 = buttonState2;
  buttonState2 = digitalRead(channelButtonPin);
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
  for (int j = 0; j < totalLeds2; j++) {
    if (j == channelDisplayed) {
      digitalWrite(channelNumberLedPins[j], HIGH);
    } else {
      digitalWrite(channelNumberLedPins[j], LOW);
    }
  }
}


void sequenceForwards() {
  pot = analogRead(A14);
  tempo = map(pot, 0, 1023, 100, 1000);

  if (millis() > lastStep + tempo) {
    lastStep = millis();

    for ( int i = 0; i < 3; i++) {
      usbMIDI.sendNoteOff(midiNotes[i], 0, 1);
    }


    countUp();

    for (int i = 0; i < 3; i++) {
      if (switchedOn[i][currentStep] == HIGH) {
        usbMIDI.sendNoteOn(midiNotes[i], 127, 1);
      }
    }
  }
}



  void countUp() {

    currentStep++;
    if (currentStep == totalLeds) {
      currentStep = 0;

    }
  }
