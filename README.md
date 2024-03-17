# Arduino-cli for developing ESP32

## Arduino-cli usage

Refer to https://arduino.github.io/arduino-cli/0.35/getting-started/

### Install arduino-cli

```
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
```

## Develop for ESP32

### Install esp32 core

```
arduino-cli core install esp32:esp32
```

### Create sketch

```
arduino-cli sketch new your\_sketch\_name
```

### Compile sketch

```
cd your\_sketch\_name

arduino-cli compile -b esp32:esp32:esp32
```

### Upload sketch

```
arduino-cli upload -p /dev/ttyUSBx -b esp32:esp32:esp32
```
