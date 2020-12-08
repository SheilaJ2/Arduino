//int ledPin1 = 28;
//int ledPin2 = 26;
//int buttonPin1 = 32;
//int buttonPin2 = 31;
int potPin= A14;
int potVal= 0;
int mappedPotVal = 0;
//int potPin2 = A15;
//int potPin3 = A16;
//int potPin4 = A17;

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  potVal = analogRead(A14);
  mappedPotVal = map(potVal, 0, 1023, 0, 255);
  Serial.write(mappedPotVal);
  delay(50);
}
