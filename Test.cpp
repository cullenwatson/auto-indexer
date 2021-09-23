#include "catch.hpp"
#include "Stringy.h"
#include"Vectory.h"
TEST_CASE("TESTING STRING CLASS", "[string]") {
    Stringy s[11];
    s[0] = Stringy("this is Stringy class");
    s[1] = Stringy("a second string");
    s[2] = Stringy("");
    s[3] = Stringy("ALL CAPITALS");
    s[4] = Stringy("");
    s[5] = Stringy("all capitals");
    s[6] = Stringy("ab");
    s[7] = Stringy("\n");
    s[8] = Stringy("cd");
    s[9] = Stringy("this is Stringy class");
    s[10]=Stringy("Caps Here");

    SECTION("EQUALITY OPERATORS") {
        REQUIRE(s[0] == Stringy("this is Stringy class"));
        REQUIRE(s[1] == Stringy("a second string"));
        REQUIRE(s[5] == Stringy("all capitals"));

        REQUIRE(s[4] == "");
        REQUIRE(s[1] == "a second string");
        REQUIRE(!(s[3] == s[5]));
    }
    SECTION("ASSIGNMENT OPERATORS") {
        Stringy str;
        str = "a second string";
        REQUIRE(str == s[1]);
        str = Stringy("a second string");
        REQUIRE(str == s[1]);
        str = "";
        REQUIRE(str == s[2]);
        str = Stringy("\n");
        REQUIRE(str == s[7]);

        REQUIRE(str == Stringy("\n"));
        str = "ab";
        REQUIRE(str == Stringy("ab"));
        str = "all capitals";
        REQUIRE(str == Stringy("all capitals"));
    }
    SECTION("ADDITION OPERATOR") {
        REQUIRE(Stringy("abcd") == s[6] + s[8]);
        REQUIRE(s[4] + s[4] == "");
        REQUIRE(s[4] + s[7] == "\n");
        REQUIRE(s[4] + s[7] + s[3] == "\nALL CAPITALS");
    }
    SECTION("GREATER THAN OPERATOR") {
        REQUIRE(s[0] > s[1]);
        REQUIRE(s[8] > s[6]);
        REQUIRE(s[8] > s[4]);
        REQUIRE(s[5] > s[3]);

        Stringy str;
        str = "aaaa";
        REQUIRE(s[9] > str);
        REQUIRE(s[5] > str);
        REQUIRE(s[6] > str);
    }
    SECTION("LESS THAN OPERATOR") {
        REQUIRE(s[1] < s[0]);
        REQUIRE(s[6] < s[8]);
        REQUIRE(s[3] < s[5]);

        Stringy str;
        str = "zero";
        REQUIRE(s[1] < str);
        REQUIRE(s[5] < str);
        REQUIRE(s[6] < str);
    }
    SECTION("[] Operator") {
        REQUIRE(s[0][1] == 'h');
        REQUIRE(s[1][3] == 'e');
        REQUIRE(s[5][4] == 'c');
    }
    SECTION("getLength Function") {
        REQUIRE(s[8].getLength() == 2);
        REQUIRE(s[1].getLength() == 15);
        REQUIRE(s[5].getLength() == 12);
    }
    SECTION("Substring Function") {
        REQUIRE(s[0].substring(0, 4) == "this");
        REQUIRE(s[0].substring(0, 5) == "this ");
        REQUIRE(s[1].substring(1, 4) == " sec");
    }
    SECTION("c_str Function") {
        REQUIRE(strcmp(s[0].c_str(), "this is Stringy class") == 0);
        REQUIRE(strcmp(s[4].c_str(), "") == 0);
        REQUIRE(strcmp(s[6].c_str(), "ab") == 0);
    }
    SECTION("Find Function") {
        REQUIRE(s[0].find('z') == -1);
        REQUIRE(s[5].find('a') == 0);
        REQUIRE(s[8].find('d') == 1);
    }
    SECTION("toLower Function") {
        s[0].toLower();
        REQUIRE(strcmp(s[0].c_str(), "this is stringy class") == 0);
        s[3].toLower();
        REQUIRE(strcmp(s[3].c_str(), "all capitals") == 0);
        s[10].toLower();
        REQUIRE(strcmp(s[10].c_str(), "caps here") == 0);
    }
    SECTION("toUpper Function") {
        s[0].toUpper();
        REQUIRE(strcmp(s[0].c_str(), "THIS IS STRINGY CLASS") == 0);
        s[5].toUpper();
        REQUIRE(strcmp(s[5].c_str(), "ALL CAPITALS") == 0);
        s[10].toUpper();
        REQUIRE(strcmp(s[10].c_str(), "CAPS HERE") == 0);
    }
    SECTION("removeChar Function") {
        s[0].removeChar('t');
        REQUIRE(strcmp(s[0].c_str(), "his is Sringy class")==0);
        s[6].removeChar('a');
        REQUIRE(strcmp(s[6].c_str(), "b")==0);
        s[4].removeChar('H');
        REQUIRE(strcmp(s[4].c_str(), "")==0);
    }
};
TEST_CASE("TESTING VECTOR CLASS", "[vector]") {
    class Test{
        int A;
    public:
        Test(int a){ A = a;}
        Test(){A = 0;}
        bool operator== (const Test&t) const{return A == t.A;}
    };
    Vectory<Test> myVector;
    myVector.push_back(Test(3));
    myVector.push_back(Test(5));
    myVector.push_back(Test(6));

    SECTION("ASSIGNMENT Operator") {
        Vectory<int>numVector, numVector2;
        numVector.push_back(1);
        numVector.push_back(2);
        numVector.push_back(3);
        numVector2 = numVector;
        REQUIRE(numVector2[0]==1);
        REQUIRE(numVector2[1] == 2);
        REQUIRE(numVector2[2] == 3);
    }
    SECTION("PUSHBACK FUNCTION & [] Operator") {
        REQUIRE(myVector[0] == 3);
        REQUIRE(myVector[1] == 5);
        REQUIRE(myVector[2] == 6);
    }
    SECTION("AT FUNCTION") {
        REQUIRE(myVector.at(0) == 3);
        REQUIRE(myVector.at(1) == 5);
        REQUIRE(myVector.at(2) == 6);
    }
    SECTION("POP FUNCTION & GETSIZE()") {
        myVector.pop_back();
        REQUIRE(myVector.getSize() == 2);
        myVector.pop_back();
        REQUIRE(myVector.getSize() == 1);
        myVector.pop_back();
        REQUIRE(myVector.getSize() == 0);
    }
    SECTION("RESIZE FUNCTION & GETARRAYSIZE()"){
        myVector.resize();
        REQUIRE(myVector.getArraySize() == 20);
        myVector.resize();
        REQUIRE(myVector.getArraySize() == 40);
        myVector.resize();
        REQUIRE(myVector.getArraySize() == 80);
    }
};