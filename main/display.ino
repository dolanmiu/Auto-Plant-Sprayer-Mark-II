String createLoadingSpinner() {
  const long milliSecs = millis() % 1000;
  String loadingChar;

  if (milliSecs < 250) {
    loadingChar = "|";
  } else if (milliSecs < 500) {
    loadingChar = "/";
  } else if (milliSecs < 750) {
    loadingChar = "-";
  } else if (milliSecs < 1000) {
    loadingChar = "\\";
  }

  return loadingChar;
}


