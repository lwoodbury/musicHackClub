

float scale[] = {130.81, 155.56, 174.61, 196, 233.08, 261.63, 311.13, 349.23, 392, 466.16, 523.25};



void playNote() {

  M5.Speaker.tone(scale[random(11)], 50); //beep

  digitalWrite(3, HIGH);
  delay(20);
  digitalWrite(3, LOW);

}
