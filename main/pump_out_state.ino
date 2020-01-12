
void pumpOutState() {
  openValves();
  setWaterRelayToRemoveWater();
  turnOnPump();
  turnOffDosingPump();
}

