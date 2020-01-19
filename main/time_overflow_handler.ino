unsigned long previousMillis = 0;
unsigned long currentTime;

void tickTime() {
  const unsigned long currentMillis = millis();
  const float delta = currentMillis - previousMillis;
  previousMillis = currentMillis;

  // Due to overflow
  if (delta < 0) {
    return;
  }

  currentTime = currentTime + delta;
}

unsigned long getSystemTime() {
  return currentTime;
}

void resetTime() {
  currentTime = 0;
}
