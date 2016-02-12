/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 
 ----------------------------------------------
 Modifed by Valeriy V Dmitriev aka Valmat 
 As an example to the Pino library

*/

#include <Pino.h>

Pino button(2, Pino::Mode::in);
Pino led(13, Pino::Mode::out);

void setup() {}

void loop() {
    // check if the button is pressed.
    if (button.isOn()) {
        // turn LED on:
        led.on();
    } else {
        // turn LED off:
        led.off();;
    }
}