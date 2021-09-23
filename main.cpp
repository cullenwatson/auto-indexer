#include <iostream>
#include "catch_setup.h"
#include"File.h"

int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        File myFile;
        myFile.readFile(argv[1]);

    }
    return 0;
}