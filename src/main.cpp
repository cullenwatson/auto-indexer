#include <iostream>
#include"IndexMaker.h"


int main(int argc, char** argv) {

    // parse file
    cout<<"parsing..."<<endl;
    IndexMaker::parseFile(argv[1]);

    // output the results
    IndexMaker::outputIndex(argv[2]);


    cout<<"finished parsing"<<endl;
    return 0;
}
