Pino — is the Arduino pins control library
=======
Actually Pino is a very lightweight zero-cost, header-only wrapper over the native Arduino functions. Which makes it easier to writing and reading a code for the Arduino.

A couple of simple examples
--------
[Native arduino functions](https://www.arduino.cc/en/Tutorial/AnalogInput):
```c
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
```
Using the Pino library:
```c
#include <Pino.h>

Pino sensor(A0);                  // select the input pin for the potentiometer
Pino led(13, Pino::Mode::out);    // select the pin for the LED

void setup() {}

void loop() {
  int sensorValue = sensor.read();
  led.on();
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  led.off();;
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
```

For more examples, see the [examples](examples) directory


![Pino](/Pino.png?raw=true)
