# Pino — is an Arduino pins control library

Actually Pino is a very lightweight zero-cost, header-only wrapper over the native Arduino functions. It makes easier to writing and reading a code for an Arduino sketches and libraries.

### A couple of simple examples

Using the Pino library:
```c
#include <Pino.h>

Pino sensor(A0);                  // select the input pin for the potentiometer
Pino led(13, Pino::Mode::out);    // select the pin for the LED

void setup() {}

void loop() {
  auto sensorValue = sensor.read();
  led.on();
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  led.off();
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
```

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

For more examples, see the [examples](examples) directory

## Main features
#### Zero-cost
Pino does not increase the size of the code, it does not take up more memory. Using Pino is as effective as the use of native functions.
#### Legacy compatyble
You don't need to change the old code to start using *Pino*. All operations which have been applied to a numeric type of a pin number in the old code will be workable with the object *Pino* class.

This code will work as expected:
```c
Pino led = 13;
void setup() {
  pinMode(led, OUTPUT);
}
```
And this code too:
```c
Pino rs = 2, e =3, db4 = 4, db5 = 5, db6 = 6, db7 = 7;
LiquidCrystal lcd(rs, e, db4, db5, db6,  db7);
```
It looks strange, but you can even write `digitalWrite(pin, HIGH);`, where `pin` is object of Pino. Although in this case, `pin.on()` looks much clearer.

The examples above are possible because Pino object can be implicitly converted to numeric types and back.


At last. When you need to set the pin mode, you can specify the mode in initialization
```c
Pino led(13, Pino::Mode::out);
``` 
or use method `mode`
```c
Pino led(13);
void setup() {
  led.mode(Pino::Mode::out);
}
``` 
if you so habitual.

You can even write `led.mode(OUTPUT)` instead of `led.mode(Pino::Mode::out)`, if you like. Although I do not like this.

### Concordance table
The table below shows the corresponding class methods to native functions:

| `Pino` methods    |native functions|
| ------------- |:-------------:|
| `pin.on()`      |`digitalWrite(pin, HIGH)`|
| `pin.off()`      |`digitalWrite(pin, LOW)`|
| `pin.turn(value)`      |`digitalWrite(pin, (value ? HIGH : LOW ) )`|
| `pin.isOn()`      |`(HIGH == digitalRead(_pin))`|
| `pin.read()`      |`analogRead(pin)`|
| `pin.read(toLow, toHigh)`      |`map(analogRead(pin), LOW, HIGH, toLow, toHigh);`|
| `pin.write(value)`      |`analogWrite(pin, value)`|
| `pin.tone(frequency, duration)`      |`tone(pin, frequency, duration)`|
| `pin.tone(frequency)`      |`tone(pin, frequency, 0)`|
| `pin.noTone()`      |`noTone(pin)`|
| `pin.pulseInOn(timeout)`      |`pulseIn(pin, HIGH, timeout)`|
| `pin.pulseInOn()`      |`pulseIn(pin, HIGH)`|
| `pin.pulseInOff(timeout)`      |`pulseIn(pin, LOW, timeout)`|
| `pin.pulseInOff()`      |`pulseIn(pin, LOW)`|
| `pin.shiftOut(clockPin, val)`      |`shiftOut(pin, clockPin, MSBFIRST, val)`|
| `pin.shiftOutRe(clockPin, val)`      |`shiftOut(pin, clockPin, LSBFIRST, val)`|
| `pin.shiftIn(clockPin)`      |`shiftIn(pin, clockPin, MSBFIRST)`|
| `pin.shiftInRe(clockPin)`      |`shiftIn(pin, clockPin, LSBFIRST)`|

More details see [surce code](src/Pino.h)


[The MIT License](LICENSE)


![Pino](/extras/Pino.png?raw=true)
