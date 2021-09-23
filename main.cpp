#include <iostream>
#include <fstream>
#include "catch_setup.h"
#include"Vectory.h"
class MyClass{
    int a, b;
public:
    MyClass(int A, int B){
        a = A;
        b = B;
    }
};
int main(int argc, char** argv) {
    /*if(argc == 1) {
        runCatchTests();
    }*/
    //else {

    // this section works
    Vectory<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    for(int i=0;i<test.getSize();i++)
        cout<<test[i]<<endl;


    // using a class, my vector doesn't work. help.
    Vectory<MyClass> test2;
    MyClass obj1(5,3);
    MyClass obj2(4,8);
    MyClass obj3(1,2);

    test2.push_back(obj1);
    test2.push_back(obj2);
    test2.push_back(obj3);
    /*for(int i=0;i<test.getSize();i++)
        cout<<test[i]<<endl;*/
    //}
    return 0;
}