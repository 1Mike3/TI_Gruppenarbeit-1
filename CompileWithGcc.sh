#!/bin/bash

#compiles the files using the gc-compiler and places the files into the GCC_Executables folder

#gcc -Wall -Wextra       compile flags

#compile the first files and create the corresponding object files in the GCC_Executables Folder
#2.1
gcc -I./src_2.x_Specific -I./include -I./srcGeneral -Wall -Wextra ./implementations/2.1sortAndSearch.c \
./src_2.x_Specific/binarySearchAlgorithm.c ./src_2.x_Specific/generateRandomStruct.c \
./src_2.x_Specific/quicksortInt.c ./src_2.x_Specific/quicksortString.c ./srcGeneral/randnum.c -o ./GCC_Executables/2.1sortAndSearch
#2.2
gcc -I./src_2.x_Specific -I./include -I./srcGeneral -Wall -Wextra ./implementations/2.2sortAndSearchSTDLIB.c \
./src_2.x_Specific/binarySearchAlgorithm.c ./src_2.x_Specific/generateRandomStruct.c \
./src_2.x_Specific/quicksortInt.c ./src_2.x_Specific/quicksortString.c ./srcGeneral/randnum.c -o ./GCC_Executables/2.2sortAndSearchSTDLIB
#2.3
gcc -I./src_2.x_Specific -I./include -I./srcGeneral -Wall -Wextra ./implementations/2.3SortAndSearchBenchmark.c \
./src_2.x_Specific/binarySearchAlgorithm.c ./src_2.x_Specific/generateRandomStruct.c \
./src_2.x_Specific/quicksortInt.c ./src_2.x_Specific/quicksortString.c ./srcGeneral/randnum.c -o ./GCC_Executables/2.3sortAndSearchBenchmark