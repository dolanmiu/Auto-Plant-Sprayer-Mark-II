const unsigned long CYCLE_DURATION = 5000L;
const unsigned long CYCLE_HALF_DURATION = CYCLE_DURATION / 2;

unsigned long startOfCycleMillis = 0;

bool isFirstCycleStart = true;

void cycleState() {
  if (isFirstCycleStart) {
    startOfCycleMillis = millis();
    nextCycleStartTimeMillis = startOfCycleMillis + MILLIS_PER_DAY;
    isFirstCycleStart = false;
  }
  
  turnOffDosingPump();

  unsigned long currentMillis = millis();
  unsigned long delta = currentMillis - startOfCycleMillis;

  if (delta < CYCLE_HALF_DURATION) {
    displayText("Cycling. Pumping water in");
    openValves();
    setWaterRelayToRemoveWater();
    turnOnPump();
  } else if (delta < CYCLE_DURATION) {
    displayText("Cycling. Pumping water out");
    openValves();
    setWaterRelayToAddWater();
    turnOnPump();
  } else {
    // Finished
    turnOffPump();
    closeValves();
    state = OFF;
    isFirstCycleStart = true;
  }
}
