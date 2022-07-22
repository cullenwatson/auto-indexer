//
// Created by pc on 9/24/21.
//

#ifndef INC_21F_PA02_INDEXMAKER_H
#define INC_21F_PA02_INDEXMAKER_H
#include<algorithm>
#include<cstring>
#include<fstream>
#include <iostream>
#include"Stringy.h"
#include"Vectory.h"
#include"Keyphrase.h"
class IndexMaker {
public:
    static void parseFile(char input[]);
    static void addKeyphrase(Stringy temp, Stringy temp2, char page[]);
    static void outputIndex(char outputFile[]);
};


#endif //INC_21F_PA02_INDEXMAKER_H
