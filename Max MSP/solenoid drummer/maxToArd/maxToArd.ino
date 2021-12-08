/* 
 *  Serial comms with start- and end-markers taken 
 *  from examples on Arduino blog
 *  
 *  Designed to control solenoids with 
 *  a sequencer from Max MSP
 *  
 *  This code is in the public domain
 *  Luke Woodbury 8th December 2021
 */

const byte numChars = 32;
char receivedChars[numChars];
char in1[numChars] = "snd1\0";

const int LED_pin = 13;
const int sndP1 = 12;
const int sndP2 = 11;
const int sndP3 = 10;
const int sndP4 = 9;

boolean newData = false;

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
    pinMode(LED_pin, OUTPUT);
    pinMode(sndP1, OUTPUT);
    pinMode(sndP2, OUTPUT);
    pinMode(sndP3, OUTPUT);
    pinMode(sndP4, OUTPUT);
}

void loop() {
    recvWithStartEndMarkers();
    //showNewData();
    outPut();
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
 
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}

void outPut(){
  if (newData == true) {
        if(strcmp(receivedChars, "snd1-1") == 0){
          digitalWrite(LED_pin, HIGH);
          digitalWrite(sndP1, HIGH);
          Serial.println("Solenoid 1 ON");
        }
        else if(strcmp(receivedChars, "snd1-0") == 0){
          digitalWrite(LED_pin, LOW);
          digitalWrite(sndP1, LOW);
          Serial.println("Solenoid 2 OFF");
        }

   //Serial.println(in1);    
   Serial.println(receivedChars);
   newData = false;
    }
  
}
