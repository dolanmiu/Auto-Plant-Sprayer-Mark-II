const unsigned long CYCLE_DURATION = 10000L;
const unsigned long CYCLE_HALF_DURATION = 3000L;

bool isFirstCycleStart = true;

void cycleState() {
  if (isFirstCycleStart) {
    resetTime();
    isFirstCycleStart = false;
  }

  const unsigned long delta = getSystemTime();

  if (delta < CYCLE_HALF_DURATION) {
    drawCycleText("Spraying water...", (float)delta / (float)CYCLE_DURATION);
    turnOnPump();
  } else if (delta < CYCLE_DURATION) {
    drawCycleText("Cooling off...", (float)delta / (float)CYCLE_DURATION);
    turnOffPump();
  } else {
    // Finished
    turnOffPump();
    state = OFF;
    isFirstCycleStart = true;
    setCycleStartTime();
  }
}

void drawCycleText(const String text, const float ratio) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  display.println("Running....");
  display.println(text);
  const int margin = 3;
  const int yPosition = 18;
  const int height = 14;
  const int width = 128;
  display.drawRect(margin, yPosition, width - margin - margin, height, WHITE);
  display.fillRect(margin + 2, yPosition + 2, (ratio * (float)128) - margin - margin - 4, height - 4, WHITE);
  const int percent = (int)(ratio * 100);
  const int characterOffset = percent < 10 ? 2 : 5;
  display.setCursor(64 - characterOffset, 21);
  display.setTextColor(WHITE, BLACK);
  display.print(percent);
  display.display();
}

