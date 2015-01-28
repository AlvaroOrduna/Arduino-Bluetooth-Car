/*
 * Copyright (C) 2015 Álvaro Orduna León
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Motor.h"

Motor::Motor() {
}

void Motor::setMotor(int pinA, int pinB, int pinPWM) {
    pinMode(pinA, OUTPUT);
    _pinA = pinA;
    pinMode(pinB, OUTPUT);
    _pinB = pinB;
    pinMode(pinPWM, OUTPUT);
    _pinPWM = pinPWM;
}


void Motor::go(int speed) {
    if (speed > 0) {
        digitalWrite(_pinA, HIGH);
        digitalWrite(_pinB, LOW);
        analogWrite(_pinPWM, speed);
    } else {
        digitalWrite(_pinA, LOW);
        digitalWrite(_pinB, HIGH);
        analogWrite(_pinPWM, -speed);
    }
}

void Motor::stop() {
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, LOW);
    analogWrite(_pinPWM, 0);
}
