# Arduino-cli for developing ESP32

## Arduino-cli usage

Refer to https://arduino.github.io/arduino-cli/0.35/getting-started/

### Install arduino-cli

```
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
```

### Set PATH environment variable

Add the following command to ~/.bashrc.

```
export PATH=arduino-cli-path:$PATH
```

The following command will take effect immediately.

```
source ~/.bashrc
```

## Develop for ESP32

### Install esp32 core

```
arduino-cli core install esp32:esp32
```

### Create sketch

```
arduino-cli sketch new your_sketch_name
```

### Compile sketch

```
cd your_sketch_name

arduino-cli compile -b esp32:esp32:esp32
```

Or specify the target file of the directory

```
cd your_sketch_name

arduino-cli compile -b esp32:esp32:esp32 --output-dir target_directory
```

### Enable USB device authority

Create 99-usbdev.rules in /etc/udev/rules.d

Add the following content to /etc/udev/rules.d/99-usbdev.rules

```
/* Add permission to all user to have complete acces to CH340 */
SUBSYSTEM=="usb", ATTRS{idVendor}=="1a86", ATTRS{idProduct}=="7523", GROUP="dialout", MODE:="0666"
```
Then restart linux system.

### Upload sketch

If the USB device is /dev/ttyUSB0, please use the following command:

```
arduino-cli upload -p /dev/ttyUSB0 -b esp32:esp32:esp32
```

Or specify the target file

```
arduino-cli upload -p /dev/ttyUSB0 -b esp32:esp32:esp32 --input-file your_target_file
```

### Debug sketch

Default baudrate for 9600, it can set the baudrate via -c option.

```
arduino-cli monitor -p /dev/ttyUSB0 -c 115200
```
