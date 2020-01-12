
void pumpInState() {
  Serial.println("Pump In State");
  openValves();
  setWaterRelayToAddWater();
  turnOnPump();
  turnOffDosingPump();
}

