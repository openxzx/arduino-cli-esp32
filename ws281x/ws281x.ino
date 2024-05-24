
/* Install lib command for arduino-cli lib install "Adafruit NeoPixel" */
#include <Adafruit_NeoPixel.h>

#define WS281X_PIN	4

// Refer to https://adafruit.github.io/Adafruit_NeoPixel/html/class_adafruit___neo_pixel.html
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, WS281X_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  colorWipe(strip.Color(16, 0, 0), 3000);
  colorWipe(strip.Color(0, 16, 0), 3000);
  colorWipe(strip.Color(0, 0, 16), 3000);
}

void colorWipe(uint32_t c, uint16_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}
