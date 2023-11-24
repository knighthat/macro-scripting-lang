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


class Script {

private:
    void run0() {
        for (const auto& task: tasks)
            task->execute();
    }

public:
    int repeat = 1;
    vector<unique_ptr<Task>> tasks;

    [[noreturn]] void run() {
      if (repeat == 0) {
          while (true) {
              run0();
          }
      }
      else if (repeat > 0){
          for (int i = 0 ; i < repeat ; i++){
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

    if (argc == 4 || string(argv[2]) != "--loop") {

        script.repeat = stoi(argv[3]);

    } else {
        print_help(argv[0]);
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