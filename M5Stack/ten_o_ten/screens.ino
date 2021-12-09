


void introScreen() {

  // draw intro title
  // todo: add in SEGA style "dahhhdah"

  M5.Speaker.tone(30000, 1); // weird stuff happens with a frequency this high and it makes a fizzle sound!


  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(TFT_WHITE);

  M5.Lcd.setCursor(42, 100);
  M5.Lcd.setTextSize(4);
  M5.Lcd.println(F("ten oh ten"));
  delay(1000);

  M5.Lcd.setCursor(70, 150);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println(F("1-bit sequencer"));
  delay(2000);

}
