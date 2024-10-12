/*
 * 130 Motor + HR1124S/HR1154D Motor drive chip
 */

#define TOUCH  14

#define INA    5
#define INB    13

int touch = 0;
int motor_status = 0;

void setup() {
  pinMode(TOUCH, INPUT);

  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
}

void loop() {
  touch = digitalRead(TOUCH);
  if (touch) {
    delay(10);
    touch = digitalRead(TOUCH);
    if (touch) {
      motor_status = digitalRead(INB);
      if (motor_status) {
        digitalWrite(INB, LOW);
      } else {
        digitalWrite(INB, HIGH);
      }
    }
  }
  while (1) {
    touch = digitalRead(TOUCH);
    if (!touch)
      break;
  }
}
