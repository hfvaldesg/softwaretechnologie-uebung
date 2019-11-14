# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(uebung1)
set (PROJECT_SOURCES punkt.h polygon.h rechteck.h)

add_executable(ue1 main.cpp ${PROJECT_SOURCES})
