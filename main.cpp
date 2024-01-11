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
#include <memory>

#include "Utils.h"
#include "token/Token.h"
#include "task/MoveMouseTask.h"
#include "task/PressTask.h"
#include "task/WaitTask.h"
#include "task/WriteTask.h"
#include "task/MouseClickTask.h"

using namespace std;


class Argument {

public:
    string file;
    int loop = 1;
    long start_delay = 0;
};

class Script {

private:
    void run0() {
        for (const auto& task: tasks)
            task->execute();
    }

public:
    Argument argument;
    vector<unique_ptr<Task>> tasks;

    [[noreturn]] void run() {
      if (argument.loop == 0) {
          while (true) {
              run0();
          }
      }
      else if (argument.loop > 0){
          for (int i = 0 ; i < argument.loop ; i++){
              run0();
          }
      }
    }
};

void print_help(char *file_name) {
    cout << "Usage: " << file_name << " <file> --[option]" << endl;
    cout << "  - loop [times]: Repeat this script [times] times. '0' will repeat forever";
}

int main(int argc, char **argv) {

    if (argc < 2) {
        cout << "Missing file to read" << endl;
        print_help(argv[0]);
        return 1;
    }

    Script script;

    int option;
    while ((option = getopt(argc, argv, "l:d:")) != -1) {

        try {
            switch ( option ) {
                case 'l':
                    cout << "Number of loop(1): " << optarg << endl;
                    script.argument.loop = stoi(optarg);
                    break;
                case 'd':
                    cout << "Delay " << optarg << " millis before running" << endl;
                    script.argument.start_delay = stol(optarg);
                    break;
                default:
                    break;
            }
        } catch (const invalid_argument& e) {
            continue;
        }
    }

    for ( int i = 1 ; i < argc ; i++ ) {

        string arg = argv[i];

        if (arg.rfind('-', 0) == 0) {
            i++;
            continue;
        }

        script.argument.file = arg;
        break;
    }

    cout << "File: " << script.argument.file << endl;
    cout << "Loop: " << script.argument.loop << endl;
    cout << "Delay: "<< script.argument.start_delay << endl;

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
        unique_ptr<Task> task_ptr;
        switch (*keyword) {

            case Keyword::MOVE:
                if (MoveMouseTask::validate(data))
                    task_ptr = make_unique<MoveMouseTask>(data);
                break;
            case Keyword::CLICK:
                if (MouseClickTask::validate(data))
                    task_ptr = make_unique<MouseClickTask>(data);
                break;
            case Keyword::PRESS:
                if (PressTask::validate(data))
                    task_ptr = make_unique<PressTask>(data);
                break;
            case Keyword::WRITE:
                if (WriteTask::validate(data))
                    task_ptr = make_unique<WriteTask>(data);
                break;
            case Keyword::WAIT:
                if (WaitTask::validate(data))
                    task_ptr = make_unique<WaitTask>(data);
                break;
        }

        script.tasks.push_back(std::move(task_ptr));
    }

    script.run();
}