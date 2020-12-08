bool sequences[3][4] = {
  { HIGH, LOW, HIGH, LOW},
  { LOW, HIGH, HIGH, LOW},
  { HIGH, LOW, HIGH, HIGH}
};

int sequenceLedPins[4] = { 32, 30, 28 , 26 };

int currentChannel = 0;

int channelLedPins[3] = {35, 34, 33};

int channelButtonPin = 31;
bool buttonState = LOW;
bool lastButtonState = LOW;

void setup() {
  Serial.begin(9600);
  for (int i = 0; int < 4; i++) {
    pinMode(sequenceLedPins[i], OUTPUT);
  }
  for (int i = 0; i < 3; i++) {
    pinMode(channelNumberLedPins[i], OUTPUT);
  }
  pinMode(channelButtonPin, INPUT);
}

void loop() {
  updateLeds();
  checkButton();
}

void checkButton() {
  lastButtonState = buttonState;
  buttonState = digitalRead(channelButtonPin);
  if (lastButtonState == LOW and buttonState == HIGH) {
    countUp();
    delay(5);
  } else if (lastButtonState == HIGH and buttonState == LOW) {
    delay(5);
  }
}
void updateLeds() {
  updateSequenceLeds();
  updateChannelLeds();
}

void countUp() {
  currentChannel++
  if (currentChannel >= 3) {
    currentChannel = 0; //set it back to 0
  }
}

void updateSequenceLeds() {
   for (int i = 0; i < 4; i++) {
    digitalWrite(sequencesLedPins[i], sequences[currentChannel][i]);
  }
}

void updateChannelLeds() {
  for(int i = 0; i < 3; i++) {
    if(i= currentChannel) {
      digitalWrite(ChannelLedPins[i], HIGH);
    } else {
      digitalWrite(channelLedPins[i], LOW); //turn the other channels off
    }
  }
}
