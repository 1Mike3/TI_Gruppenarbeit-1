cmake_minimum_required(VERSION 3.23)
project(Gruppenarbeit_TI C)

set(CMAKE_C_STANDARD 99)

add_executable(Gruppenarbeit_TI main.c src/mergesort.c src/quicksort.c src/insertionsort.c src/bubblesort.c src/_genFunc.c include/allfunclib.h)

