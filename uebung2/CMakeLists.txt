# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(uebung2)
include_directories("./include")
set (PROJECT_SOURCES ./src/main.cpp)


add_executable(ue2 ${PROJECT_SOURCES})