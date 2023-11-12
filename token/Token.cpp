/*
 * Author knighthat
 * Created on 11/7/23
 * Copyright (c) 2023. All rights reserved.
 *
 * Project is licensed under
 * GNU Lesser General Public License (LGPL)
 */


#include "Token.h"
#include "../Validator.h"


const Keyword *valueOf(string &value) {
    static const map<string, Keyword> map =
            {
                    {"MOVE",  Keyword::MOVE},
                    {"PRESS", Keyword::PRESS},
                    {"WRITE", Keyword::WRITE},
                    {"WAIT",  Keyword::WAIT},
                    {"CLICK", Keyword::CLICK}
            };
    auto result = map.find(value);
    return result != map.end() ? &(result->second) : nullptr;
}

const TokenType *valueOf(char c) {
    TokenType type = TokenType::STRING;
    if (c >= '0' && c <= '9')
        type = TokenType::NUMBER;

    return new TokenType(type);
}

vector<Token> Token::parse(string &from) {
    vector<Token> tokens;

    for (int i = 0; i < from.length(); i++) {
        char c = from[i];

        if (isNumeric(c)) {

            string numBuilder;
            while (isNumeric(c)) {
                numBuilder += c;
                i++;
                c = from[i];
            }

            auto token = new Token(TokenType::NUMBER, numBuilder);
            tokens.push_back(*token);

        } else if (isChar(c)) {

            string strBuilder;
            while (isChar(c)) {
                strBuilder += c;
                i++;
                c = from[i];
            }

            auto token = new Token(TokenType::STRING, strBuilder);
            tokens.push_back(*token);

        }
    }

    return tokens;
}
