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

#include "Car.h"

Car::Car(int pinLA, int pinLB, int pinLPWM, int pinRA, int pinRB, int pinRPWM) {
    _motorI.setMotor(pinLA, pinLB, pinLPWM);
    _motorD.setMotor(pinRA, pinRB, pinRPWM);
}

void Car::go(int speed, int distribution) {
    if (speed == 0) {
        this->stop();
    } else {
        speed = adjustSpeed(speed);
        distribution = adjustDistribution(distribution);

        if (distribution > 0) {
            _motorI.go(speed);
            _motorD.go(speed * (1 - ((double) abs(distribution) / MAX_DISTRIBUTION)));
        } else if (distribution < 0) {
            _motorI.go(speed * (1 - ((double) abs(distribution) / MAX_DISTRIBUTION)));
            _motorD.go(speed);
        } else {
            _motorI.go(speed);
            _motorD.go(speed);
        }
    }
}

void Car::stop() {
    _motorI.stop();
    _motorD.stop();
}

int Car::adjustSpeed(int speed) {
    speed = min(speed, MAX_SPEED);
    speed = max(speed, -MAX_SPEED);

    return speed;
}

int Car::adjustDistribution(int distribution) {
    distribution = min(distribution, MAX_DISTRIBUTION);
    distribution = max(distribution, -MAX_DISTRIBUTION);

    return distribution;
}
