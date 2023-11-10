//
// Created by tnknight on 11/9/23.
//


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
