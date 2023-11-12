/*
 * Author knighthat
 * Created on 11/8/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#ifndef MACROSCRIPTINGLANG_WRITETASK_H
#define MACROSCRIPTINGLANG_WRITETASK_H

#include "Task.h"


class WriteTask : public Task {

public:
    explicit WriteTask(string &source);

    static bool validate(string &source);

    string command() override { return "type"; }

    string args() override;
};


#endif //MACROSCRIPTINGLANG_WRITETASK_H
