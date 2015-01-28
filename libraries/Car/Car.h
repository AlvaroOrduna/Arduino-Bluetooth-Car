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

#ifndef Car_h
#define Car_h

#include "Motor.h"

class Car {

    public:
        Car(int pinLA, int pinLB, int pinLPWM, int pinRA, int pinRB, int pinRPWM);

        void go(int speed, int distribution);
        void stop();

    private:
        int adjustSpeed(int speed);
        int adjustDistribution(int distribution);

        Motor _motorD;
        Motor _motorI;
};

#endif
