void dosingState() {
  closeValves();
  setWaterRelayToRemoveWater();
  turnOffPump();
  turnOnDosingPump();

  drawDosingText();
  checkIfDosingNeedsToStop();
}

void checkIfDosingNeedsToStop() {
  int val = digitalRead(DOSING_BUTTON);
  if (val == 1) {
    state = OFF;
  }
}

void drawDosingText() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Dosing");
  display.setCursor(62, 15);
  display.setTextSize(2);
  display.println(createLoadingSpinner());

  display.display();
}
