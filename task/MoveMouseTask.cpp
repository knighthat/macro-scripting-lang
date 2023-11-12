/*
 * Author tnknight
 * Created on 11/9/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#include "MoveMouseTask.h"


bool MoveMouseTask::validate(string &source) {

    if (source.find(',') == string::npos) {
        cout << "Missing delimiter(,)" << endl;
        return false;
    }

    for (string &str: split(source, ','))
        for (char c: str)
            if (!isNumeric(c)) {
                cout << c << " is not a number" << endl;
                return false;
            }

    return true;
}

MoveMouseTask::MoveMouseTask(string &source) : Task(Token::parse(source)) {}

string MoveMouseTask::args() {
    return tokens[0].value + " " + tokens[1].value;
}
