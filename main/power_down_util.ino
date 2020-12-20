bool getPowerSwitch() {
  const int val = digitalRead(ON_OFF_SWITCH);
  if (val == 0) {
    return false;
  } else {
    return true;
  }
}
