//
// Created by tnknight on 11/9/23.
//

#ifndef MACROSCRIPTINGLANG_MOVEMOUSETASK_H
#define MACROSCRIPTINGLANG_MOVEMOUSETASK_H


#include "Task.h"


class MoveMouseTask : public Task {

public:
    explicit MoveMouseTask(string &source);

    static bool validate(string &source);

    string command() override { return "mousemove"; }

    string args() override;
};


#endif //MACROSCRIPTINGLANG_MOVEMOUSETASK_H
