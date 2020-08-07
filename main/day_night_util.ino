int dayNightRingBufferIndex = 0;
const int DAY_NIGHT_BUFFER_SIZE = 200;
int dayNightSensorRingBuffer[DAY_NIGHT_BUFFER_SIZE] = {};

// memset(dayNightSensorRingBuffer, analogRead(LIGHT_SENSOR), DAY_NIGHT_BUFFER_SIZE);

unsigned long calculateDayNight() {
  const int dayNightValue = analogRead(LIGHT_SENSOR);

  dayNightSensorRingBuffer[dayNightRingBufferIndex] = dayNightValue;

  dayNightRingBufferIndex++;

  if (dayNightRingBufferIndex >= DAY_NIGHT_BUFFER_SIZE) {
    dayNightRingBufferIndex = 0;
  }

  long sum = 0L;  // sum will be larger than an item, long for safety.
  for (int i = 0; i < DAY_NIGHT_BUFFER_SIZE; i++) {
    sum += dayNightSensorRingBuffer[i];
  }
  return  ((float) sum) / DAY_NIGHT_BUFFER_SIZE;
}
