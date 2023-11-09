cmake_minimum_required(VERSION 3.26)
project(MacroScriptingLang)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        MacroScriptingLang
        main.cpp
        token/TokenType.cpp
        token/TokenType.h
        keyword/Keyword.cpp
        keyword/Keyword.h
        token/Token.cpp
        token/Token.h
        Validator.h
        task/Task.cpp
        task/Task.h
        task/PressTask.cpp
        task/PressTask.h
        Validator.cpp
        Validator.h
        task/MoveTask.cpp
        task/MoveTask.h
        task/WaitTask.cpp
        task/WaitTask.h
        task/WriteTask.cpp
)
