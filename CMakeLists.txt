cmake_minimum_required(VERSION 3.23)
project(Gruppenarbeit_TI C)

set(CMAKE_C_STANDARD 99)

add_executable(Gruppenarbeit_TI main.c cmake-build-debug/mergesort.c cmake-build-debug/quicksort.c cmake-build-debug/insertionsort.c)
