  int ledPin1 = 31;
  int ledPin2 = 30;
  int ledPin3 = 29;
  int ledPin4 = 28;
  int buttonPin1 = 33;
  int buttonPin2 = 34;
  int potValue = 0 ;
 
void setup() {
  pinMode(ledPin1 , OUTPUT);
  pinMode(ledPin2 , OUTPUT);
  pinMode (ledPin3 , OUTPUT);
  pinMode(ledPin4 , OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(31, OUTPUT);
  Serial.begin(9600);
  }

void loop() {
  potValue = analogRead(A13);

  if (digitalRead(buttonPin1) == HIGH) {
    Serial.println("led is blinking");
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    delay(potValue);
    Serial.println("led is not blinking");
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    delay(potValue);
  }

  if (digitalRead(buttonPin2) == HIGH) {
    digitalWrite (ledPin1, HIGH);
    delay(potValue);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(potValue);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    delay(potValue);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
    delay(potValue);
    digitalWrite(ledPin4, LOW);
  }
}
