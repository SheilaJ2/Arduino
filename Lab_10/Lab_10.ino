int pot = A14;
int potInt = 0;
int mappedPotInt = 0; //circle size

int pot2 = A15;
int potInt2 = 0;
int mappedPotInt2 = 0; //x axis of circle

int pot3 = A16;
int potInt3 = 0;
int mappedPotInt3 = 0; //y axis of circle

int pot4 = A17;
int potInt4 = 0;
int mappedPotInt4 = 0; //Square thing color

int pot5 = A18;
int potInt5 = 0;
int mappedPotInt5 = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.write(0); //thing number 1
  
  potInt = analogRead(pot);
  mappedPotInt = map(potInt, 0, 1023, 1, 255);
  Serial.write(mappedPotInt); //thing number 2
 

  potInt2 = analogRead(pot2);
  mappedPotInt2 = map(potInt2, 0, 1023, 1, 255);
  Serial.write(mappedPotInt2); //thing number 3

  
  potInt3 = analogRead(pot3);
  mappedPotInt3 = map(potInt3, 0, 1023, 1, 255);
  Serial.write(mappedPotInt3); //thing number 4

  potInt4 = analogRead(pot4);
  mappedPotInt4 = map(potInt4, 0, 1023, 1, 255);
  Serial.write(mappedPotInt4); //thing number 5

  potInt5 = analogRead(pot5);
  mappedPotInt5 = map(potInt5, 0, 1023, 1, 255);
  Serial.write(mappedPotInt5); //thing number 6


  
  delay(50); 
}
