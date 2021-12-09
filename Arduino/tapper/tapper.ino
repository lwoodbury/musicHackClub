// ===================
//       TAPPER
// ===================

#define tapA 9
#define tapB 10
#define tapC 11
#define tapD 12

int beat = 0;

int ping = 50;

void setup() {

  pinMode(tapA, OUTPUT);
  pinMode(tapB, OUTPUT);
  pinMode(tapC, OUTPUT);
  pinMode(tapD, OUTPUT);

}

void loop() {


  if (beat % 17 == 0) {
    digitalWrite(tapA, HIGH);
  } else if (beat % 13 == 0) {
    digitalWrite(tapB, HIGH);
  } else if (beat % 9 == 0) {
    digitalWrite(tapC, HIGH);
  } else if (beat % 6 == 0) {
    digitalWrite(tapD, HIGH);
  }
  delay(ping + beat%25);

  digitalWrite(tapA, LOW);
  digitalWrite(tapB, LOW);
  digitalWrite(tapC, LOW);
  digitalWrite(tapD, LOW);

  delay(20 + (beat%4)*10);
  beat++;


}
