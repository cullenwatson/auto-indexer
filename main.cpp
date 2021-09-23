/**
 * Fall 2021 PA 02 Template Repo.
 */

#include <iostream>
#include <fstream>
#include"Vectory.h"
/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"

int main(int argc, char** argv) {
    /*if(argc == 1) {
        runCatchTests();
    }*/
    //else {
    Vectory<int> hello;
    hello.push_back(1);
    hello.push_back(2);
    hello.push_back(3);


    for(int i=0;i<hello.getSize();i++)
        cout<<hello[i]<<endl;
    //}
    return 0;
}
