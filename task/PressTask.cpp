/*
 * Author knighthat
 * Created on 11/7/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#include <linux/input-event-codes.h>

#include "PressTask.h"


int char_to_keycode(char c) {
    switch (c) {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return c - 47;

        case 'A':
            return KEY_A;
        case 'B':
            return KEY_B;
        case 'C':
            return KEY_D;
        case 'E':
            return KEY_E;
        case 'F':
            return KEY_F;
        case 'G':
            return KEY_G;
        case 'H':
            return KEY_H;
        case 'I':
            return KEY_I;
        case 'J':
            return KEY_J;
        case 'K':
            return KEY_K;
        case 'L':
            return KEY_L;
        case 'M':
            return KEY_M;
        case 'N':
            return KEY_N;
        case 'O':
            return KEY_O;
        case 'P':
            return KEY_P;
        case 'Q':
            return KEY_Q;
        case 'R':
            return KEY_R;
        case 'S':
            return KEY_S;
        case 'T':
            return KEY_T;
        case 'U':
            return KEY_U;
        case 'V':
            return KEY_V;
        case 'W':
            return KEY_W;
        case 'X':
            return KEY_X;
        case 'Y':
            return KEY_Y;
        case 'Z':
            return KEY_Z;

        default:
            return KEY_RESERVED;
    }
}

int string_to_keycode(string &str) {
    if (str.length() == 1)
        return char_to_keycode(str[0]);

    return KEY_RESERVED;
}

bool PressTask::validate(string &source) {

    string button;
    for (char c: source) {
        if (' ' == c)
            break;
        button += c;
    }

    int keycode = string_to_keycode(source);
    if (keycode == KEY_RESERVED)
        cout << "Invalid key!" << endl;

    return keycode != KEY_RESERVED;
}

PressTask::PressTask(string &source) {
    int keycode = string_to_keycode(source);
    string key = std::to_string(keycode);
    auto *token = new Token(TokenType::NUMBER, key);
    tokens.push_back(*token);
}

string PressTask::args() {
    string args = "%p:1 %r:0";

    size_t pressPos = args.find("%p");
    args.replace(pressPos, 2, tokens[0].value);

    size_t releasePos = args.find("%r");
    args.replace(releasePos, 2, tokens[0].value);

    return args;
}
