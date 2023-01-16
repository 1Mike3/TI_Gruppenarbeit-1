cmake_minimum_required(VERSION 3.23)
project(Gruppenarbeit_TI C)

set(CMAKE_C_STANDARD 99)

add_executable(Gruppenarbeit_TI main.c srcGeneral/mergesort.c srcGeneral/quicksort.c srcGeneral/insertionsort.c
        srcGeneral/bubblesort.c srcGeneral/_genFunc.c include/allfunclib.h srcGeneral/randnum.c
        implementations/1.1implementation.c implementations/1.3comparison.c
        implementations/1.4linkedLists.c implementations/1.2benchmark.c srcGeneral/insertionsort_2.c implementations/2.1sortAndSearch.c src_2.x_Specific/binarySearchAlgorithm.c src_2.x_Specific/binarySearchAlgorithm.h src_2.x_Specific/generateRandomStruct.c src_2.x_Specific/generateRandomStruct.h src_2.x_Specific/userInputSearch.c src_2.x_Specific/userInputSearch.h src_2.x_Specific/quicksortString.c src_2.x_Specific/quicksortString.h)
target_include_directories (Gruppenarbeit_TI PUBLIC include)
target_include_directories (Gruppenarbeit_TI PUBLIC src_2.x_Specific)