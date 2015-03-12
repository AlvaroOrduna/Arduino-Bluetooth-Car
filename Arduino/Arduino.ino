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

#include <Car.h>
#include <Motor.h>
#include <Parser.h>
#include <ProximitySensor.h>
#include <SoftwareSerial.h>

#define RxD 0
#define TxD 1

#define STATE_GO   'G'
#define STATE_STOP 'S'

#define SECURITY_DISTANCE 10

Car car(12, 13, 11, 7, 6, 5);

Parser parser;

ProximitySensor proximitySensor;

SoftwareSerial BTSerial(RxD, TxD);

char last_state;

int speed;
int distribution;

void setup() {
  Serial.begin(9600);
  Serial.flush();
  
  BTSerial.begin(9600);
  BTSerial.flush();
  BTSerial.println("Ready");
  delay(500);
  
  last_state = STATE_STOP;
}

void loop() {
  if (BTSerial.available()){
    String phrase = BTSerial.readString();
    parser.setPhrase(phrase);

    speed = parser.getSpeed();
    distribution = parser.getDistribution();
    
    if (proximitySensor.getDistance() > SECURITY_DISTANCE || speed < 0) {
      car.go(speed, distribution);
      last_state = STATE_GO;
    } else if (speed == 0) {
      car.stop();
      last_state = STATE_STOP;
    } else {
      BTSerial.println("Bloqueado");
      car.stop();
      last_state = STATE_STOP;
    }
  } else {
    if (proximitySensor.getDistance() < SECURITY_DISTANCE && speed > 0 && last_state != STATE_STOP) {
      BTSerial.println("Bloqueado");
      car.stop();
      last_state = STATE_STOP;
    }
  }
}
