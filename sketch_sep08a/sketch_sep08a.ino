 void setup() {
  Serial.begin(9600);
  pinMode(31, OUTPUT) ; // put your setup code here, to run once:
  pinMode(33, INPUT) ;
 }

 void loop() {
  if (digitalRead(33) == HIGH) { // this calls for another braket
    Serial.println ("led is blinking");
  digitalWrite(31, HIGH); // putting 3.3v on Pin 31:
  delay(1000); // When high it'll pause for 1000 miliseconds
  Serial.println("led is not blinking");
  digitalWrite(31, LOW); // setting for lows
  delay(1000); // when on low it'll pause for 1000 miliseconds
  }
 }
