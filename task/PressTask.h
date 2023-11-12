/*
 * Author knighthat
 * Created on 11/7/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#ifndef MACROSCRIPTINGLANG_PRESSTASK_H
#define MACROSCRIPTINGLANG_PRESSTASK_H

#include "Task.h"


class PressTask : public Task {

public:
    explicit PressTask(string &source);

    static bool validate(string &source);

    string command() override { return "key"; }

    string args() override;
};


#endif //MACROSCRIPTINGLANG_PRESSTASK_H
