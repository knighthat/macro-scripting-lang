cmake_minimum_required(VERSION 3.26)
project(MacroScriptingLang)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        MacroScriptingLang
        main.cpp
        Validator.h
        Validator.cpp
        Validator.h
        Utils.h
        token/Token.cpp
        token/Token.h
        task/MoveMouseTask.cpp
        task/MoveMouseTask.h
        task/PressTask.cpp
        task/PressTask.h
        task/WriteTask.cpp
        task/WriteTask.h
        task/WaitTask.cpp
        task/WaitTask.h
        task/Task.cpp
        task/Task.h
        Utils.cpp
)
