cmake_minimum_required(VERSION 2.8)
PROJECT(Parse)

add_executable(m lex.c Parse.cpp Symbol.cpp main.cpp)
