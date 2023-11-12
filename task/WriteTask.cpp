/*
 * Author knighthat
 * Created on 11/8/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#include <cctype>

#include "WriteTask.h"


bool WriteTask::validate(string &source) {
    if (source.empty())
        cout << "Empty string to write!" << endl;
    return !source.empty();
}

WriteTask::WriteTask(string &source) : Task() {
    Token token = *(new Token(TokenType::STRING, source));
    tokens.push_back(token);
}

string WriteTask::args() {
    return "\"" + tokens[0].value + "\"";
}
