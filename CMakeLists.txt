cmake_minimum_required(VERSION 3.14)
project(21f_PA02)

set(CMAKE_CXX_STANDARD 14)

configure_file(test_book.txt test_book.txt NEWLINE_STYLE UNIX)

add_executable(21f_PA02 main.cpp catch.hpp catch_setup.cpp catch_setup.h Vectory.h Test.cpp Stringy.cpp Stringy.h Keyphrase.cpp Keyphrase.h)
