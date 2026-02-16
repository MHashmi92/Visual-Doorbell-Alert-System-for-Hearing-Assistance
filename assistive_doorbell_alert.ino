#include <Adafruit_NeoPixel.h>

#define LED_PIN   6
#define NUM_LEDS  18
#define MIC_PIN   A0

const int THRESHOLD = 400;
const int SAMPLE_COUNT = 200;
const int REQUIRED_COUNT = 3;

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int loudCounter = 0;
bool alertActive = false;
unsigned long alertStartTime = 0;
const unsigned long ALERT_DURATION = 3000; // 3 seconds

// =============================
// Setup
// =============================
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(80);
  strip.show();
}

// =============================
// Main Loop
// =============================
void loop() {

  int amplitude = measureAmplitude();
  Serial.println(amplitude);

  if (amplitude > THRESHOLD) {
    loudCounter++;
  } else {
    loudCounter = 0;
  }

  // Activate alert
  if (loudCounter > REQUIRED_COUNT && !alertActive) {
    alertActive = true;
    alertStartTime = millis();
  }

  // Run alert pattern
  if (alertActive) {
    flashAlert();

    if (millis() - alertStartTime > ALERT_DURATION) {
      alertActive = false;
      strip.clear();
      strip.show();
    }
  }
}

// =============================
// Measure Sound Amplitude
// =============================
int measureAmplitude() {
  int minVal = 1023;
  int maxVal = 0;

  for (int i = 0; i < SAMPLE_COUNT; i++) {
    int val = analogRead(MIC_PIN);
    if (val < minVal) minVal = val;
    if (val > maxVal) maxVal = val;
  }

  return maxVal - minVal;
}

// =============================
// Flashing Alert Pattern
// =============================
void flashAlert() {

  static bool state = false;
  static unsigned long lastToggle = 0;

  if (millis() - lastToggle > 300) {  // flash speed
    lastToggle = millis();
    state = !state;

    if (state) {
      strip.fill(strip.Color(255, 0, 0));  // Red flash
    } else {
      strip.clear();
    }

    strip.show();
  }
}
