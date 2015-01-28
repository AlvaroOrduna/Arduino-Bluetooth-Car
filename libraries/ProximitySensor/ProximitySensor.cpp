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

#include "ProximitySensor.h"

#define pinTriger A0
#define pinEcho A1

ProximitySensor::ProximitySensor() {
  pinMode(pinTriger, OUTPUT);
  pinMode(pinEcho, INPUT);
}

long ProximitySensor::getDistance() {

    digitalWrite(pinTriger, LOW);
    delayMicroseconds(2);

    digitalWrite(pinTriger, HIGH);
    delayMicroseconds(10);

    digitalWrite(pinTriger, LOW);
    long duration = pulseIn(pinEcho, HIGH);

    return duration/58.2;
}
