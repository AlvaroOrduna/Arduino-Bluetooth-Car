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

#include "Parser.h"

Parser::Parser() {
}

Parser::Parser(String phrase) {
    _phrase = phrase;
    _dividerIndex = _phrase.indexOf("|");
}

void Parser::setPhrase(String phrase) {
    _phrase = phrase;
    _dividerIndex = _phrase.indexOf("|");
}

String Parser::getPhrase() {
    return _phrase;
}

void Parser::print() {
    Serial.print("Phrase::");
    Serial.print(_phrase);
}

void Parser::println() {
    Serial.print("Phrase::");
    Serial.println(_phrase);
}

int Parser::getSpeed() {
    if (_dividerIndex > 0) {
        return _phrase.substring(0, _dividerIndex).toInt();
    } else {
        return _phrase.substring(0).toInt();
    }
}

int Parser::getDistribution() {
    if (_dividerIndex > 0) {
        return _phrase.substring(_dividerIndex + 1).toInt();
    } else {
        return 0;
    }
}
