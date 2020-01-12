// Valve Control
void openValves() {
  digitalWrite(WATER_OUTPUT_VALVE, LOW);
  digitalWrite(WATER_INPUT_VALVE, LOW);
}

void closeValves() {
  digitalWrite(WATER_OUTPUT_VALVE, HIGH);
  digitalWrite(WATER_INPUT_VALVE, HIGH);
}

// Relay Control
void setWaterRelayToAddWater() {
  digitalWrite(WATER_OUTPUT_RELAY, LOW);
  digitalWrite(WATER_INPUT_RELAY, LOW);
}

void setWaterRelayToRemoveWater() {
  digitalWrite(WATER_OUTPUT_RELAY, HIGH);
  digitalWrite(WATER_INPUT_RELAY, HIGH);
}


// Pump Control
void turnOnPump() {
  digitalWrite(WATER_PUMP, LOW);
}

void turnOffPump() {
  digitalWrite(WATER_PUMP, HIGH);
}

// Dosing Control
void turnOnDosingPump() {
  digitalWrite(DOSING_PUMP, LOW);
}

void turnOffDosingPump() {
  digitalWrite(DOSING_PUMP, HIGH);
}
