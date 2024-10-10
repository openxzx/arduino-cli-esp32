
/* Install lib command for arduino-cli lib install "Adafruit NeoPixel" */
#include <Adafruit_NeoPixel.h>

#define WS281X_PIN	4
#define PIXEL_NUM   4

#define MICRO_PIN	      34
#define SOUND_CTRL_VAL	300

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_NUM, WS281X_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);

  strip.begin();
  strip.show();
}

void loop() {
  int val = analogRead(MICRO_PIN);
  Serial.println(val);
  if (val >= SOUND_CTRL_VAL) {
    colorWipe(strip.Color(255, 255, 255), 10000);
    colorWipe(strip.Color(0, 0, 0), 30);
  }
}

void colorWipe(uint32_t c, uint16_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}
