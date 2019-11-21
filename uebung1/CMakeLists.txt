# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(uebung1)
include_directories("./include")
set (PROJECT_SOURCES main.cpp)


add_executable(ue1 ${PROJECT_SOURCES})
