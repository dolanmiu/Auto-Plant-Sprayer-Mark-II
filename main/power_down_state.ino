void powerDownState() {
  drawPowerDownText();

  const bool powerSwitch = getPowerSwitch();

  if (powerSwitch == true) {
    state = OFF;
  }
}

void drawPowerDownText() {
  display.clearDisplay();

  if (checkIfDisplayIsOn()) {
    display.setTextColor(WHITE);

    display.drawBitmap(28, 12, off_bmp, DAY_NIGHT_WIDTH, DAY_NIGHT_HEIGHT, 1);

    display.setCursor(50, 13);
    display.setTextSize(2);
    display.println("Off");
  }

  display.display();
}
