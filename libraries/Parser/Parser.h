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

#ifndef Parser_h
#define Parser_h

#include "Arduino.h"

class Parser {

    public:
        Parser();
        Parser(String phrase);

        void setPhrase(String phrase);
        String getPhrase();

        void print();
        void println();

        int getSpeed();
        int getDistribution();

    private:
        String _phrase;
        int _dividerIndex;
};

#endif
