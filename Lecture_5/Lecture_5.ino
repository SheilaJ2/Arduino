int ledPins[4] = {32, 30, 28, 26};
int totalLeds = 4;
int tempo = 400;
int totalSteps = 4;
unsigned long lastStepTime = 0;
int currentStep = 0;
int pot5 = 0;
int toggle = 25;


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < totalLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(toggle, INPUT);
  }
}


void loop() {
  if (digitalRead(toggle) == HIGH) {
  sequenceForwards();
  } else {
  sequenceBackwards();
  }
}


void sequenceForwards() {
  pot5 = analogRead(A12);

  if (millis() >= lastStepTime + tempo + pot5) {
    lastStepTime = millis();
    digitalWrite(ledPins[currentStep], LOW);
    currentStep++;
    if (currentStep == totalSteps) {
      currentStep = 0;
    }
    digitalWrite(ledPins[currentStep], HIGH);
    Serial.println(currentStep);
  }
}

void sequenceBackwards() {
  if (millis() >= lastStepTime + tempo + pot5) {
    lastStepTime = millis();
    digitalWrite(ledPins[currentStep], LOW);
    currentStep--;
    if (currentStep < 0) {
      currentStep = totalSteps - 1;
    }
    digitalWrite(ledPins[currentStep], HIGH);
    Serial.println(currentStep);
  }
}
