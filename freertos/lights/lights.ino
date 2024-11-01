#define LED_RED_PIN     5
#define LED_YELLOW_PIN  13
#define LED_GREEN_PIN   12

void led_red_task(void *parameters) {
  while (1) {
    digitalWrite(LED_RED_PIN, HIGH);
    Serial.println("Led Red On.\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(LED_RED_PIN, LOW);
    Serial.println("Led Red Off.\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void led_yellow_task(void *parameters) {
  while (1) {
    digitalWrite(LED_YELLOW_PIN, HIGH);
    Serial.println("Led Yellow On.\n");
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    digitalWrite(LED_YELLOW_PIN, LOW);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println("Led Yellow Off.\n");
  }
}

void led_green_task(void *parameters) {
  while (1) {
    digitalWrite(LED_GREEN_PIN, HIGH);
    Serial.println("Led Green On.\n");
    vTaskDelay(4000 / portTICK_PERIOD_MS);
    digitalWrite(LED_GREEN_PIN, LOW);
    Serial.println("Led Green Off.\n");
    vTaskDelay(4000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);

  xTaskCreate(led_red_task, "Red", 1024, NULL, 3, NULL);
  xTaskCreate(led_yellow_task, "Yellow", 1024, NULL, 3, NULL);
  xTaskCreate(led_green_task, "Green", 1024, NULL, 3, NULL);
}

void loop() {
}
