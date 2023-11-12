/*
 * Author knighthat
 * Created on 11/7/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#ifndef MACROSCRIPTINGLANG_TOKEN_H
#define MACROSCRIPTINGLANG_TOKEN_H


#include <string>
#include <map>
#include <vector>

using namespace std;


enum class Keyword {
    MOVE,
    CLICK,
    PRESS,
    WRITE,
    WAIT
};

const Keyword *valueOf(string &value);


enum class TokenType {
    STRING,
    NUMBER,
};

const TokenType *valueOf(char c);


class Token {

public:
    TokenType type;
    string value;

    explicit Token(TokenType type, string &values) {
        this->type = type;
        this->value = values;
    }

    static vector<Token> parse(string &from);
};

#endif //MACROSCRIPTINGLANG_TOKEN_H
