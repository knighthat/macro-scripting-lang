/*
 * Author tnknight
 * Created on 11/9/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#ifndef MACROSCRIPTINGLANG_UTILS_H
#define MACROSCRIPTINGLANG_UTILS_H


#include <vector>
#include <string>
#include <cctype>

using namespace std;


vector<string> split(string &source, char splitter);

string trim(string &source);

#endif //MACROSCRIPTINGLANG_UTILS_H
