/*
 * Author knighthat
 * Created on 11/7/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#include <cstdlib>

#include "Task.h"


void Task::execute() {
    string cmd = "ydotool %cmd %args";

    size_t cmdPos = cmd.find("%cmd");
    cmd.replace(cmdPos, 4, command());

    size_t argsPos = cmd.find("%args");
    cmd.replace(argsPos, 5, args());

    cout << "Command: " << cmd << endl;
    system(cmd.c_str());
}
