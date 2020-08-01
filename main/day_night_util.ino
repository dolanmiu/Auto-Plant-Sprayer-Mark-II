unsigned long calculateDayNight() {
  const int dayNightValue = analogRead(LIGHT_SENSOR);

  Serial.println(dayNightValue);

  return dayNightValue;
}
