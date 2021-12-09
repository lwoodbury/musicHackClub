


boolean withinBounds(int givenStep) {
  if (loopState == 1) {
    if (direction == FORWARD) {
      return givenStep >= startStep && givenStep <= stepPos;
    } else if (direction == BACKWARD) {
      return givenStep >= stepPos && givenStep <= endStep;
    }
  } else {
    return givenStep >= startStep && givenStep <= endStep;
  }
}

//Draws the grid on the display
void drawGrid(void) {

  uint16_t color = TFT_WHITE;
  int currentStep = 0;

  playBeep = false;

  for (int y = 0; y < GRIDY; y++) {

    for (int x = 0; x < GRIDX; x++) {
      // The cursor
      if (currentStep == stepPos) {
        
        color = RED; //resolveCursorColour();

        if (grid[x][y] == 1) {
          playBeep = true;
        }

      }
      // Loop Points
      else if (isLooping() && withinBounds(currentStep)) {
          color = grid[x][y] == 1 ? color16(200, 200, 255) : color16(0, 0, 255);
      }
      // Normal grid elements
      else {
        color = grid[x][y] == 1 ? WHITE : BLACK;
      }

      M5.Lcd.fillRect(40 + CELLXY * x, 0 + CELLXY * y, CELLXY, CELLXY, color);
      currentStep++;
    }
  }
}


//Initialise Grid

void initGrid(void) {

  for (int16_t x = 0; x < GRIDX; x++) {
    for (int16_t y = 0; y < GRIDY; y++) {

      if (random(100) < 50) {
        grid[x][y] = 1;
      } else {
        grid[x][y] = 0;
      }
    }
  }
}
