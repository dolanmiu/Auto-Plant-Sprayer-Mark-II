
void offState() {
  long timeLeft = nextCycleStartTimeMillis - millis();
  if (timeLeft > 0) {
    displayText("Idle. Next Cycle in: " + timeToString(timeLeft));
  } else {
    displayText("Idle. Cycle should be happening by now");
  }

  closeValves();
  turnOffPump();
  setWaterRelayToRemoveWater();
  turnOffDosingPump();
}

String timeToString(long t) {
  static char str[12];

  long hours = floor(t / MILLIS_PER_HOUR);
  long mins = floor((t % MILLIS_PER_HOUR) / MILLIS_PER_MINUTE);
  long secs = floor((t % MILLIS_PER_MINUTE) / MILLIS_PER_SECOND);

  sprintf(str, "%02ld:%02ld:%02ld", hours, mins, secs);
  return str;
}
