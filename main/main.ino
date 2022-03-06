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

const int DISPLAY_BUTTON = 6;

const int ON_OFF_SWITCH = 9;

const int DURATION_DIAL = A3;

const int LIGHT_SENSOR = A0;

unsigned long NEXT_CYCLE_START_MILLIS = MILLIS_PER_DAY;

enum STATE_ENUM {CYCLE, OFF, NIGHT, POWER_DOWN};

// Global Variables
uint8_t state = OFF;
unsigned long smoothedPotValue = analogRead(DURATION_DIAL);

void setup() {
  Serial.begin(9600);

  pinMode(CYCLE_BUTTON, INPUT);
  digitalWrite(CYCLE_BUTTON, HIGH);

  pinMode(DISPLAY_BUTTON, INPUT);

  pinMode(ON_OFF_SWITCH, INPUT);
  digitalWrite(ON_OFF_SWITCH, HIGH);

  pinMode(DURATION_DIAL, INPUT);

  pinMode(WATER_PUMP, OUTPUT);
  
  // pinMode(LIGHT_SENSOR, INPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Hack to allow time for pot to initialise
  delay(3000);
  smoothedPotValue = analogRead(DURATION_DIAL);
  setCycleStartTime();
}

void loop() {
  tickTime();
  
  switch (state) {
    case CYCLE:
      cycleState();
      break;
    case NIGHT:
      nightState();
      break;
    case POWER_DOWN:
      powerDownState();
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
  Serial.println("Setting next start time:");
  NEXT_CYCLE_START_MILLIS = calculateIntervalTime() * MILLIS_PER_MINUTE;
  Serial.println(NEXT_CYCLE_START_MILLIS);
}

