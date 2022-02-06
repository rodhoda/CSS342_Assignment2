cmake_minimum_required(VERSION 3.21)
project(Assignment2Work)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment2Work XMLDriver.cpp XMLNode.cpp XMLNode.h parseline.cpp test.xml)
