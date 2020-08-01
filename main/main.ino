#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const Adafruit_SSD1306 display(128, 32, &Wire, -1);

const unsigned long MILLIS_PER_MINUTE = 60000L;
const unsigned long MILLIS_PER_DAY = 86400000L;
const unsigned long MILLIS_PER_HOUR = 3600000L;
const unsigned long MILLIS_PER_SECOND = 1000L;
const unsigned long MINS_PER_HOUR = 60L;
const unsigned long MINS_PER_DAY = 1440L;

const int WATER_PUMP = 7;

const int CYCLE_BUTTON = 8;

const int DURATION_DIAL = A3;

const int LIGHT_SENSOR = A0;

unsigned long NEXT_CYCLE_START_MILLIS = MILLIS_PER_DAY;

enum STATE_ENUM {CYCLE, OFF};

// Global Variables
uint8_t state = OFF;


void setup() {
  Serial.begin(9600);

  pinMode(CYCLE_BUTTON, INPUT);
  digitalWrite(CYCLE_BUTTON, HIGH);

  pinMode(DURATION_DIAL, INPUT);

  pinMode(WATER_PUMP, OUTPUT);
  
  pinMode(LIGHT_SENSOR, INPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  setCycleStartTime();
}

void loop() {
  tickTime();
  
  switch (state) {
    case CYCLE:
      cycleState();
      break;
    case OFF:
    default:
      offState();
      break;
  }

  readInputs();
}

void readInputs() {
  const int val = digitalRead(CYCLE_BUTTON);
  if (val == 0) {
    state = CYCLE;
  }
}

void setCycleStartTime() {
  NEXT_CYCLE_START_MILLIS = calculateIntervalTime() * MILLIS_PER_MINUTE;
  Serial.println("Setting next start time:");
  Serial.println(NEXT_CYCLE_START_MILLIS);
}

