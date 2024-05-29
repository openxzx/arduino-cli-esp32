#include <array>

using namespace std;

#define RED_PIN     18
#define GREEN_PIN   19
#define BLUE_PIN    23

#define RED_STR     "red"
#define GREEN_STR   "green"
#define BLUE_STR    "blue"
#define YELLOW_STR  "yellow"
#define WHITE_STR   "white"
#define BLACK_STR   "black"

#define DATA_SIZE   8

int idx = 0;
array <char, 8> data = {0};

void setup() {
  Serial.begin(115200);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

void loop() {
  idx = 0;

  if (Serial.available() > 0) {
    while (Serial.available() > 0 && idx < data.size() - 1) {
      char tmp = Serial.read();
      if (tmp == '\r')
        break;
      data[idx++] = tmp;
    }
    data[idx] = '\0';

    if (!strncmp(&data[0], RED_STR, strlen(RED_STR))) {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
    } else if (!strncmp(&data[0], GREEN_STR, strlen(GREEN_STR))) {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
    } else if (!strncmp(&data[0], BLUE_STR, strlen(BLUE_STR))) {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);
    } else if (!strncmp(&data[0], YELLOW_STR, strlen(YELLOW_STR))) {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
    } else if (!strncmp(&data[0], WHITE_STR, strlen(WHITE_STR))) {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
    } else if (!strncmp(&data[0], BLACK_STR, strlen(BLACK_STR))) {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
    }
  }
}
