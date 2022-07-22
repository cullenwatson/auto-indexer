cmake_minimum_required(VERSION 3.14)
project(21f_PA02)

set(CMAKE_CXX_STANDARD 14)

configure_file(data/test_book.txt data/test_book.txt)

add_executable(21f_PA02 src/main.cpp src/Vectory.h src/Stringy.cpp src/Stringy.h src/Keyphrase.cpp src/Keyphrase.h src/IndexMaker.cpp src/IndexMaker.h)
