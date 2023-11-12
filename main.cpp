/*
 * Author knighthat
 * Created on 11/8/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Utils.h"
#include "token/Token.h"
#include "task/MoveMouseTask.h"
#include "task/PressTask.h"
#include "task/WaitTask.h"
#include "task/WriteTask.h"
#include "task/MouseClickTask.h"

using namespace std;


int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Missing file to read" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "Failed to open file " << argv[1] << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << "Tokenizing: " << line << endl;

        vector<string> parts = split(line, ':');
        if (parts.size() < 2) {
            cout << "No colon(:) found! Skipping..." << endl;
            continue;
        }

        const Keyword *keyword = valueOf(parts[0]);
        if (keyword == nullptr) {
            cout << "Unknown keyword: " << parts[0] << endl;
            return 1;
        }

        string data = trim(parts[1]);
        Task *task = nullptr;
        switch (*keyword) {

            case Keyword::MOVE:
                if (MoveMouseTask::validate(data))
                    task = new MoveMouseTask(data);
                break;
            case Keyword::PRESS:
                if (PressTask::validate(data))
                    task = new PressTask(data);
                break;
            case Keyword::WRITE:
                if (WriteTask::validate(data))
                    task = new WriteTask(data);
                break;
            case Keyword::WAIT:
                if (WaitTask::validate(data))
                    task = new WaitTask(data);
                break;
            case Keyword::CLICK:
                if (MouseClickTask::validate(data))
                    task = new MouseClickTask(data);
                break;
        }

        if (task == nullptr)
            return 1;
        else
            task->execute();
    }
}