
//---------------------------
//       TEN OH TEN
//     1-bit sequencer
//---------------------------

#define M5STACK_MPU6886
#include <M5Stack.h>

#define GRIDX 10
#define GRIDY 10
#define CELLXY 24

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

float accXSmoothed = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float pitch = 0.0F;
float roll  = 0.0F;
float yaw   = 0.0F;

boolean playBeep = false;
boolean beepPlayed = false;

uint8_t grid[GRIDX][GRIDY];

float stepFloat = 0;
int stepPos = 0;
int lastStepPos = 0;

#define DEFAULTLOOP 0
#define STARTLOOP 1
#define RUNLOOP 2


unsigned int loopState = 0;
int startStep = 0;
int endStep = 100;
#define FORWARD 1
#define BACKWARD -1
unsigned int direction = FORWARD;


//---------------------------
//          SETUP
//---------------------------

void setup() {

  M5.begin();
  M5.Power.begin();
  M5.IMU.Init();

  introScreen();

  initGrid();

  M5.update();

  pinMode(3, OUTPUT);
}


void updateLoop() {
  if (M5.BtnA.wasPressed()) {
    loopState += 1;
    switch(loopState) {
      case 3:
        loopState = 0;
      case 0:
        startStep = 0;
        endStep = 100;
        break;
      case 1:
        if (direction == FORWARD) {
          startStep = stepPos;
        }
        else if (direction == BACKWARD) {
          endStep = stepPos;
        }
        break;
      case 2:
        if (direction == FORWARD) {
          endStep = stepPos;
        }
        else if (direction == BACKWARD) {
          startStep = stepPos;
        }
        break;
      break;
    }
  }
}

void updateStep() {
  accXSmoothed =  0.75 * accXSmoothed - 0.25 * accX;

  stepFloat += accXSmoothed;

  direction = accXSmoothed >= 0 ? FORWARD : BACKWARD;

  if (stepFloat >= endStep) {
    stepFloat = startStep;
  }
  else if (stepFloat <= startStep) {
    stepFloat = endStep;
  }

  // ------ update stepPos -------

  stepPos = round(stepFloat);

  if (stepPos != lastStepPos) {

    lastStepPos = stepPos;
    
    beepPlayed = false;  // in a new square so ready to beep again
  }
}

//---------------------------
//           LOOP
//---------------------------

void loop() {

  // ------ sensors -------

  M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  M5.IMU.getAhrsData(&pitch, &roll, &yaw);


  // ------ update stepFloat -------

  updateStep();

  updateLoop();


  // ------ drawing -------

  drawGrid();


  // ------ buttons -------


  //if (M5.BtnB.isPressed()) {
  if (true) {
    
    if ((playBeep == true) && (beepPlayed == false)) {

      playNote();
      
      playBeep = false;
      beepPlayed = true;

    }
  }


  if (M5.BtnA.wasPressed()) {
    
  }
  
    if (M5.BtnB.wasPressed()) {

      digitalWrite(3, LOW);
    
  }

  if (M5.BtnC.wasPressed()) {
    initGrid();
    M5.Speaker.tone(400, 100);
    digitalWrite(3, HIGH);
  }



  M5.update();

  // delay(1); // is the delay necessary?
}
