/*
 * Servo control via PWM signal.
 * A 180-degree servo is used here for debugging, PWM's period is 20ms, so the frequency is 50HZ.
 * Degree control examples:
 * 0   degree: duty cycle for 2.50%
 * 45  degree: duty cycle for 5.00%
 * 90  degree: duty cycle for 7.50%
 * 135 degree: duty cycle for 10.0%
 * 180 degree: duty cycle for 12.5%
 *
 * refer to https://www.arduino.cc/reference/en/libraries/esp32servo/
 *
 */

/* Install lib command for arduino-cli lib install "ESP32Servo" */
#include <ESP32Servo.h>

#define SERVO_PIN	4

Servo servo;

int i = 0;
const int degree[] = {30, 45, 60, 90, 120, 135, 150, 180};

void setup() {
  servo.setPeriodHertz(50);
  servo.attach(SERVO_PIN, 500, 2500);
}

void loop() {
  for (i = 0; i < sizeof(degree) / sizeof(int); i++) {
    servo.write(0);
    delay(1000);
    servo.write(degree[i]);
    delay(3000);
  }
}
