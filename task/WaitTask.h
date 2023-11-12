/*
 * Author knighthat
 * Created on 11/8/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#ifndef MACROSCRIPTINGLANG_WAITTASK_H
#define MACROSCRIPTINGLANG_WAITTASK_H

#include "Task.h"


class WaitTask : public Task {

public:
    explicit WaitTask(string &source);

    static bool validate(string &source);

    void execute() override;
};

#endif //MACROSCRIPTINGLANG_WAITTASK_H
