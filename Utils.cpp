/*
 * Author tnknight
 * Created on 11/9/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#include <iostream>

#include "Utils.h"


vector<string> split(string &source, char splitter) {
    vector<string> result;
    size_t lastColonPos = 0;

    for (int i = 0; i < source.length(); i++) {
        size_t start = lastColonPos;
        size_t stop;

        if (splitter == source[i]) {
            stop = i;
            lastColonPos = i + 1;
        } else if (source.length() - 1 == i)
            stop = source.length();
        else
            continue;

        size_t length = stop - start;
        string split = source.substr(start, length);
        result.push_back(split);
    }

    return result;
}

string trim(string &source) {
    size_t start = 0, end = source.length();

    while (start < end && isspace(source[start]))
        start++;

    while (end > start && isspace(source[end]))
        end--;

    return source.substr(start, end - start);
}
