// Install MFRC522_I2C lib command via arduino-cli lib install --zip-path MFRC522_I2C.zip
// Download MFRC522_I2C lib from https://github.com/openxzx/MFRC522_I2C_Library
#include "MFRC522_I2C.h"

#define RED_PIN     18
#define GREEN_PIN   19

#define SWITCH_PIN  13  // eg. Relay control
bool switch_status = false;

// IIC Pin default for GPIO21 and GPIO22
// MFRC522 IIC device for 0x28
#define MFRC522_RST_PIN	0 // Not be used, not hardware connected
MFRC522 mfrc522(0x28, MFRC522_RST_PIN);

bool ShowReaderDetails() {
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print(F("MFRC522 Software Version: 0x"));
  Serial.print(v, HEX);
  if (v == 0x91)
    Serial.print(F(" = v1.0"));
  else if (v == 0x92)
    Serial.print(F(" = v2.0"));
  else
    Serial.print(F(" (unknown)"));
  Serial.println("");
  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println(F("WARNING: Communication failure, if the MFRC522 properly connected."));
    return false;
  }
  return true;
}

void setup() {
  Serial.begin(115200);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);

  pinMode(SWITCH_PIN, OUTPUT);
  digitalWrite(SWITCH_PIN, LOW); // Switch off
  switch_status = false;

  Wire.begin();
  mfrc522.PCD_Init();
  if (ShowReaderDetails())
    digitalWrite(GREEN_PIN, HIGH);
  else
    digitalWrite(RED_PIN, HIGH);
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    delay(100);
    return;
  }
  // TODO: only print card information, don't check card information
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Control switch
  digitalWrite(GREEN_PIN, LOW);
  if (switch_status) {
    digitalWrite(SWITCH_PIN, LOW); // Switch off
    switch_status = false;
  } else {
    digitalWrite(SWITCH_PIN, HIGH); // Switch on
    switch_status = true;
  }
  delay(100);
  digitalWrite(GREEN_PIN, HIGH);
}
