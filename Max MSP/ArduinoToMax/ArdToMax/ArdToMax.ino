  /*
Send readings from LDRs straight through to Max


*/

void setup(){
  // create serial buffer
  Serial.begin(9600);
}

void loop(){
  // pot input
  int pot1 = analogRead(0);
  int pot2 = analogRead(1);
  
  // write values to serial buffer
  Serial.print("pot1 ");
  Serial.println(pot1);
  Serial.print("pot2 ");
  Serial.println(pot2);

}
