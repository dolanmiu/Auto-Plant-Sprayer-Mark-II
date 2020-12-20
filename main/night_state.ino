void nightState() {
  const unsigned long dayNight = calculateDayNight();

  drawNightText(dayNight);

  checkIfNeedToGoOff(dayNight);
}

void drawNightText(const unsigned long dayNight) {
  display.clearDisplay();

  if (checkIfDisplayIsOn()) {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println(dayNight);

    display.drawBitmap(20, 12, night_bmp, DAY_NIGHT_WIDTH, DAY_NIGHT_HEIGHT, 1);

    display.setCursor(44, 13);
    display.setTextSize(2);
    display.println("Night");
  }

  display.display();
}

void checkIfNeedToGoOff(const unsigned long dayNight) {
  if (dayNight <= 300) {
    state = OFF;
  }
}
