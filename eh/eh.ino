if (turnOn == HIGH and octave == LOW) {
    blinkLed(potsMapped[0]);
    blinkLed2(potsMapped[1]);
    blinkLed3(potsMapped[2]);
    blinkLed4(potsMapped[3]);
  } else if (octave == HIGH and turnOn == HIGH) {
    blinkLed(potsMapped[0] + 12);
    blinkLed2(potsMapped[1] + 12);
    blinkLed3(potsMapped[2] + 12);
    blinkLed4(potsMapped[3] + 12);
  }

}
