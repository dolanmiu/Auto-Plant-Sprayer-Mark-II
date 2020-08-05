unsigned long calculateDayNight() {
  const int dayNightValue = analogRead(LIGHT_SENSOR);

  return dayNightValue;
}
