void pumpInState() {
  Serial.println("Pump In State");
  openValves();
  setWaterRelayToAddWater();
  turnOnPump();
  turnOffDosingPump();

  drawPumpInText();
  checkIfPumpInNeedsToStop();
}

void checkIfPumpInNeedsToStop() {
  int val = digitalRead(WATER_IN_BUTTON);
  if (val == 1) {
    state = OFF;
  }
}

void drawPumpInText() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Pumping In Water");
  display.setCursor(62, 15);
  display.setTextSize(2);
  display.println(createLoadingSpinner());

  display.display();
}
