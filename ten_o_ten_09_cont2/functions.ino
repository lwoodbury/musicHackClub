
static uint16_t resolveCursorColour() {
  switch(loopState) {
    case 3:
    case 0:
    default:
      return color16((int)255, (int)0, (int)0);
    case 1:
      return color16((int)255, (int)255, (int)0);
    case 2:
      return color16(0, 255, 0);
  } 
}

static uint16_t color16(uint16_t r, uint16_t g, uint16_t b) {
  uint16_t _color;
  _color = (uint16_t)(r & 0xF8) << 8;
  _color |= (uint16_t)(g & 0xFC) << 3;
  _color |= (uint16_t)(b & 0xF8) >> 3;
  return _color;
}

static boolean isLooping() {
  switch (loopState) {
    case 1:
    case 2:
      return true;
   default:
     return false;
  }
}
