/*
 * Author knighthat
 * Created on 11/8/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#include <thread>
#include <chrono>

#include "WaitTask.h"


bool WaitTask::validate(string &source) {

    for (char c: source) {
        if (!isNumeric(c)) {
            cout << c << " is not a number!";
            return false;
        }
    }

    return true;
}

WaitTask::WaitTask(string &source) : Task(Token::parse(source)) {}

void WaitTask::execute() {
    int time = std::stoi(tokens[0].value);
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

