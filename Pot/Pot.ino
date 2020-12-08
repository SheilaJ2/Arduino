void setup() {
  Serial.begin(9600);
  pinMode (31, OUTPUT);
  }

 int potValue = 0;
 int ledPin = 31
  void loop() {
  potValue = analogRead(A13);
  Serial.println(potValue);
  delay(100);
  }
  // put your main code here, to run repeatedly:
