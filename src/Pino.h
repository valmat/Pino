/*
 *
 * Pino - is zero-cost C++ wrapper for native arduino pin-control functions which facilitates using its
 * Created by Valeriy V Dmitriev aka Valmat. December 10, 2015.
 * Released by the MIT license.
 *
 *  @author   Valeriy V Dmitriev aka valmat <ufabiz@gmail.com>
 *  @licenses MIT https://github.com/valmat/Pino/blob/master/LICENSE
 *  @repo     https://github.com/valmat/Pino
 *
 */

#pragma once

#include <Arduino.h>


class Pino
{
public:
    // Pin modes
    enum class Mode 
    {
        in  = INPUT,
        out = OUTPUT,
        up  = INPUT_PULLUP
    };

    // initialize a pin as mode.
    Pino(uint8_t pinNom, Mode mode) : _pin(pinNom)
    {
        pinMode(pinNom, static_cast<uint8_t>(mode));
    }

    // Constructor
    Pino(uint8_t pinNom) : _pin(pinNom) {}

    // Copy & Move constructors
    Pino( const Pino& ) = default;
    Pino( Pino && ) = default;
    
    // Copy & Move assigments
    Pino& operator=(const Pino &) = default;
    Pino& operator=(Pino &&) = default;

    // initialize a pin as mode.
    void mode(Mode mode) const
    {
        pinMode(_pin, static_cast<uint8_t>(mode));
    }
    // initialize a pin as mode.
    void mode(uint8_t mode) const
    {
        pinMode(_pin, mode);
    }

    // turn the pin on (HIGH is the voltage level)
    void on() const
    {
        digitalWrite(_pin, HIGH);
    }

    // turn the pin off by making the voltage LOW
    void off() const
    {
        digitalWrite(_pin, LOW);
    }

    // turn the pin to value
    void turn(bool value) const
    {
        digitalWrite(_pin, (value ? HIGH : LOW ) );
    }

    // Check if current pin is on HIGH
    bool isOn() const
    {
        return (HIGH == digitalRead(_pin));
    }

    // Reads the value from the current analog pin
    uint16_t read() const
    {
        return analogRead(_pin);
    }

    // Reads the value from the current analog pin and Re-maps its to range [toLow, toHigh]
    int32_t read(int32_t toLow, int32_t toHigh) const
    {
        return map(analogRead(_pin), LOW, HIGH, toLow, toHigh);
    }

    // Writes an analog value (PWM wave) to the pin
    void write(uint8_t value) const
    {
        analogWrite(_pin, value);
    }

    // Generates a square wave of the specified frequency (and 50% duty cycle) on a pin
    void tone(uint16_t frequency, uint32_t duration = 0) const
    {
        ::tone(_pin, frequency, duration);
    }

    // Stops the generation of a square wave triggered by tone().
    // Has no effect if no tone is being generated.
    void noTone() const
    {
        ::noTone(_pin);
    }

    // Reads a pulse HIGH on the pin.
    uint32_t pulseInOn(uint32_t timeout) const
    {
        return ::pulseIn(_pin, HIGH, timeout);
    }
    uint32_t pulseInOn() const
    {
        return ::pulseIn(_pin, HIGH);
    }

    // Reads a pulse HIGH on the pin.
    uint32_t pulseInOff(uint32_t timeout) const
    {
        return ::pulseIn(_pin, LOW, timeout);
    }
    uint32_t pulseInOff() const
    {
        return ::pulseIn(_pin, LOW);
    }

    // Shifts out a byte of data one bit at a time
    // bitOrder == MSBFIRST
    void shiftOut(uint8_t clockPin, uint8_t val) const
    {
        ::shiftOut(_pin, clockPin, MSBFIRST, val);
    }
    void shiftOut(const Pino &clockPin, uint8_t val) const
    {
        ::shiftOut(_pin, clockPin._pin, MSBFIRST, val);
    }
    // Shifts out a byte of data one bit at a time
    // bitOrder == LSBFIRST
    void shiftOutRe(uint8_t clockPin, uint8_t val) const
    {
        ::shiftOut(_pin, clockPin, LSBFIRST, val);
    }
    void shiftOutRe(const Pino &clockPin, uint8_t val) const
    {
        ::shiftOut(_pin, clockPin._pin, LSBFIRST, val);
    }

    // Shifts in a byte of data one bit at a time
    // bitOrder == MSBFIRST
    uint8_t shiftIn(uint8_t clockPin) const
    {
        return ::shiftIn(_pin, clockPin, MSBFIRST);
    }
    uint8_t shiftIn(const Pino &clockPin) const
    {
        return ::shiftIn(_pin, clockPin._pin, MSBFIRST);
    }
    // Shifts in a byte of data one bit at a time
    // bitOrder == LSBFIRST
    uint8_t shiftInRe(uint8_t clockPin) const
    {
        return ::shiftIn(_pin, clockPin, LSBFIRST);
    }
    uint8_t shiftInRe(const Pino &clockPin) const
    {
        return ::shiftIn(_pin, clockPin._pin, LSBFIRST);
    }

    // Cast to a number
    operator uint8_t () const
    {
        return _pin;
    }

private:
    uint8_t _pin;
};