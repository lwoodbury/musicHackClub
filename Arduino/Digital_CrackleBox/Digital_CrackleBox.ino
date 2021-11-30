

int a = 0;
int b = 0;
int c = 0;

bool x = true;
bool y = true;

void setup() {

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  //Serial.begin(9600);
}

void loop() {

  a = analogRead(0);
  b = analogRead(1);
  c = analogRead(2);

  if (a < b) {
    x = !x;
  }
  if (b < c) {
    y = !y;
  }

  digitalWrite(10, x);
  //digitalWrite(11, y);

  if (y) {
    tone(11, c/2);
  } else  {
    tone(11, c);
  }
}
