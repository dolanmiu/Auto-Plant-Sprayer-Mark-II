
void offState() {
  const long timeLeft = NEXT_CYCLE_START_MILLIS - getSystemTime();
  const unsigned long interval = calculateIntervalTime();
  const unsigned long dayNight = calculateDayNight();
  drawOffText("Idle. Next Cycle in: ", timeToString(timeLeft), formatIntervalTime(interval));

  turnOffPump();
  checkIfNeedToCycle();
}

String timeToString(const long t) {
  const char str[12];

  const long hours = floor(t / MILLIS_PER_HOUR);
  const long mins = floor((t % MILLIS_PER_HOUR) / MILLIS_PER_MINUTE);
  const long secs = floor((t % MILLIS_PER_MINUTE) / MILLIS_PER_SECOND);
  const long milliSecs = t % 1000;

  const bool isBlink = milliSecs > 500;
  const char* timeFormat = isBlink ? "%02ld:%02ld:%02ld" : "%02ld %02ld %02ld";

  sprintf(str, timeFormat, hours, mins, secs);
  return str;
}

void drawOffText(const String text, const String t, const String intervalText) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);

  display.drawBitmap(0, 0, day_bmp, DAY_NIGHT_WIDTH, DAY_NIGHT_HEIGHT, 1);

  display.setCursor(32, 0);
  display.setTextSize(2);
  display.println(t);

  display.setCursor(0, 18);
  display.setTextSize(1);
  display.println("Freq:");
  display.setCursor(32, 18);
  display.setTextSize(2);
  display.println(intervalText);

  display.display();
}

void checkIfNeedToCycle() {
  const long timeLeft = NEXT_CYCLE_START_MILLIS - getSystemTime();

  if (timeLeft < 0) {
    state = CYCLE;
  }
}
