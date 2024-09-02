
/* Install lib command for arduino-cli lib install "Adafruit NeoPixel" */
#include <Adafruit_NeoPixel.h>

#define WS281X_PIN	4
#define PIXEL_NUM   20

// Refer to https://adafruit.github.io/Adafruit_NeoPixel/html/class_adafruit___neo_pixel.html
// NEO_KHZ800: WS2811/WS2812/WS2812B
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_NUM, WS281X_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

// Loop for red, green, blue, white and black
void loop() {
  colorWipe(strip.Color(255, 0, 0), 3000);
  colorWipe(strip.Color(0, 255, 0), 3000);
  colorWipe(strip.Color(0, 0, 255), 3000);
  colorWipe(strip.Color(255, 255, 255), 3000);
  colorWipe(strip.Color(0, 0, 0), 3000);
}

void colorWipe(uint32_t c, uint16_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}
