/*
 * Author knighthat
 * Created on 11/10/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#ifndef MACROSCRIPTINGLANG_MOUSECLICKTASK_H
#define MACROSCRIPTINGLANG_MOUSECLICKTASK_H


#include "Task.h"


class MouseClickTask : public Task{

public:
    explicit MouseClickTask(string &source);

    string command() override {return "click";}

    string args() override;

    static bool validate(string &source);
};


#endif //MACROSCRIPTINGLANG_MOUSECLICKTASK_H
