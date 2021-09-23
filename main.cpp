#include <iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include"Stringy.h"
#include"Vectory.h"
#include "catch_setup.h"
#include"Keyphrase.h"

int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        ifstream file(argv[1]);
        char letter;
        char outerphrase[500], innerphrase[500], page[30];
        int counter=0;
        Stringy temp, temp2, temp3;
        Vectory<Keyphrase>keyphrases;
        // open file
        if (file.is_open()) {
            // loop until end of file
            while (file.get(letter)) {
                if(letter=='\n')
                    letter=' ';
                if(temp=="-1")
                    break;

                if(letter=='<'){
                    page[0]='\0';
                    while(file.get(letter)){
                        if(letter=='>') {
                            temp = page;
                            break;
                        }
                        strncat(page, &letter, 1);
                    }
                }else {
                    if (letter == '[') {
                        counter++;
                        continue;
                    }
                    if (letter == ']' && counter == 1) {
                        counter--;
                        temp2 = outerphrase;
                        temp2.toLower();

                        auto it = find(keyphrases.begin(), keyphrases.end(), Keyphrase(temp2));
                        if (it != keyphrases.end()){
                            // if it does exist, add page to Keyphrase object
                            Vectory<Stringy>pages = it->getPage();
                            auto it2 = find(pages.begin(), pages.end(), temp);
                            if(it2 == pages.end())
                                it->addPage(temp);
                        }
                        else
                            keyphrases.push_back(Keyphrase(page,temp2));

                        outerphrase[0] = '\0';
                    } else if (counter == 1) {
                        strncat(outerphrase, &letter, 1);
                    }
                    if (letter == ']' && counter == 2) {
                        counter--;
                        temp3 = innerphrase;
                        temp3.toLower();

                        auto it = find(keyphrases.begin(), keyphrases.end(), Keyphrase(temp3));
                        if (it != keyphrases.end()){
                            // if it does exist, add page to Keyphrase object
                            Vectory<Stringy>pages = it->getPage();
                            auto it2 = find(pages.begin(), pages.end(), temp);
                            if(it2 == pages.end())
                                it->addPage(temp);
                        }
                        else
                            keyphrases.push_back(Keyphrase(page,temp3));
                        innerphrase[0] = '\0';
                    } else if (counter == 2) {
                        strncat(innerphrase, &letter, 1);
                        strncat(outerphrase, &letter, 1);
                    }
                }
            } // eof is reached
            file.close();
        } // file closes
        // output keyphrases
        sort(keyphrases.begin(),keyphrases.end());

        char firstLetter;
        for(auto it = keyphrases.begin(); it!=keyphrases.end();it++){
            if(firstLetter!=it->getFirstLetter())
                cout<<"["<<it->getFirstLetter()<<"]"<<endl;
            firstLetter = it->getFirstLetter();

            cout<<*it<<endl;
        }

    }
    return 0;
}