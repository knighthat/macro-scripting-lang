/*
 * Author knighthat
 * Created on 11/10/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#include <map>
#include <iostream>
#include <sstream>

#include "MouseClickTask.h"


int get_button(string& value) {
    const map<string, int> map =
            {
                    {"LEFT", 0x00},
                    {"RIGHT", 0x01},
                    {"MIDDLE", 0x02},
                    {"FORWARD", 0x05},
                    {"BACK", 0x06}
            };
    auto it = map.find(value);
    return it == map.end() ? -1 : it->second;
}

bool MouseClickTask::validate(string &source) {
    return get_button(source) > -1;
}

MouseClickTask::MouseClickTask(string &source) {
    string value = to_string(get_button(source));
    auto* token = new Token(TokenType::NUMBER, value);
    tokens.push_back(*token);
}

string MouseClickTask::args() {
    /* 0xC0 is the combination of 0x40(down) and 0x80(up) */
    int value = stoi(tokens[0].value) + 0xC0;

    stringstream hexStr;
    hexStr << "0x" << hex << value;
    return hexStr.str();
}
