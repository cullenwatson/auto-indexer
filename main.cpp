#include <iostream>
#include "catch_setup.h"
#include"IndexMaker.h"


int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        // parse file
        IndexMaker::parseFile(argv[1]);

        // output the results
        IndexMaker::outputIndex(argv[2]);
    }
    return 0;
}
