/*
 * Author knighthat
 * Created on 11/7/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#ifndef MACROSCRIPTINGLANG_TASK_H
#define MACROSCRIPTINGLANG_TASK_H


#include <iostream>

#include "../token/Token.h"
#include "../Validator.h"
#include "../Utils.h"

using namespace std;


class Task {

public:
    vector<Token> tokens;

    explicit Task() = default;

    explicit Task(vector<Token> tokens) { this->tokens = std::move(tokens); }

    virtual void execute();

    virtual string command() { return ""; }

    virtual string args() { return ""; }
};


#endif //MACROSCRIPTINGLANG_TASK_H