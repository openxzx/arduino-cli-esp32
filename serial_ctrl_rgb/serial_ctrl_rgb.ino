#include<string.h>

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
char data[DATA_SIZE] = {0};

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
  memset(data, 0, sizeof(data));

  if (Serial.available() > 0) {
    while (Serial.available() > 0 && idx < sizeof(data) - 1) {
      char tmp = Serial.read();
      if (tmp == '\r')
        break;
      data[idx++] = tmp;
    }
    data[idx] = '\0';

    if (!strncmp(data, RED_STR, strlen(RED_STR))) {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
    } else if (!strncmp(data, GREEN_STR, strlen(GREEN_STR))) {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
    } else if (!strncmp(data, BLUE_STR, strlen(BLUE_STR))) {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);
    } else if (!strncmp(data, YELLOW_STR, strlen(YELLOW_STR))) {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
    } else if (!strncmp(data, WHITE_STR, strlen(WHITE_STR))) {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
    } else if (!strncmp(data, BLACK_STR, strlen(BLACK_STR))) {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
    }
  }
}
