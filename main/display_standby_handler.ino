enum DISPLAY_ENUM {DISPLAY_ON, DISPLAY_OFF};

// Global Variables
uint8_t displayState = DISPLAY_OFF;

long displayOnCount = 0;

const long DISPLAY_ON_DURATION = 3000;

bool checkIfDisplayIsOn() {
  const int displayButton = digitalRead(DISPLAY_BUTTON);

  if (displayState == DISPLAY_ON) {
    displayOnCount += 10;
    if (displayOnCount > DISPLAY_ON_DURATION) {
      displayOnCount = 0;
      displayState = DISPLAY_OFF;
    }

    if (displayButton == HIGH) {
      displayOnCount = 0;
    }

    return true;
  } else {
    if (displayButton == HIGH) {
      Serial.println("turning on display");
      displayState = DISPLAY_ON;
    }

    return false;
  }
}

