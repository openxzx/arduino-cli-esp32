#include <DHT.h>
#include "lcd_st7567a.h"

/*
  Install DHT lib command for arduino-cli lib install "DHT sensor library"
*/
#define DHT_PIN    13
#define DHTTYPE DHT11 // T/H Sensor for DHT11

#define SDA_PIN    21
#define SCL_PIN    22

#define TEMPERATURE_LINE  1
#define TEMPERATURE_STR   "Temperature: "
#define HUMIDITY_LINE     2
#define HUMIDITY_STR      "Humidity: "

#define T_H_COLLECT_TIME  3000 // Unit Millisecond

DHT dht(DHT_PIN, DHTTYPE);

lcd lcd(SDA_PIN, SCL_PIN);

char t_str[8];
char h_str[8];

void setup() {
  dht.begin();

  lcd.Init();
  lcd.Clear();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  dtostrf(t, strlen(t_str), 2, t_str);
  dtostrf(h, strlen(h_str), 2, h_str);

  lcd.Cursor(TEMPERATURE_LINE, 0);
  lcd.Display(TEMPERATURE_STR);
  lcd.Cursor(TEMPERATURE_LINE, strlen(TEMPERATURE_STR));
  lcd.Display(t_str);
  lcd.Cursor(HUMIDITY_LINE, 0);
  lcd.Display(HUMIDITY_STR);
  lcd.Cursor(HUMIDITY_LINE, strlen(HUMIDITY_STR));
  lcd.Display(h_str);

  delay(T_H_COLLECT_TIME);
}
