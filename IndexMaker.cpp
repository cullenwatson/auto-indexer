//
// Created by pc on 9/24/21.
//

#include "IndexMaker.h"
using namespace std;
Vectory<Keyphrase>keyphrases;
void IndexMaker::parseFile(char input[]){
    // create variables to store different inputs from file
    ifstream file(input);
    char letter;
    char outerphrase[1000], innerphrase[1000], page[30];
    int counter=0;
    Stringy temp, temp2, temp3;

    // open file
    if (file.is_open()) {
        // loop until end of file
        while (file.get(letter)) {
            // change new lines to spaces
            if(letter=='\n')
                letter=' ';
            // check if it's the end of file
            if(temp=="-1")
                break;

            // check if input is a page number
            if(letter=='<'){
                page[0]='\0';
                while(file.get(letter)){
                    if(letter=='>') {
                        temp = page;
                        break;
                    }
                    strncat(page, &letter, 1);
                }
                // otherwise check if input is a keyphrase
            }else {
                if (letter == '[') {
                    counter++;
                    continue;
                }
                // if there's a [, check for ]
                if (letter == ']' && counter == 1) {
                    // once ] is reached, convert to lowercase and decrease counter
                    counter--;
                    temp2 = outerphrase;
                    temp2.toLower();

                    // add  inner level keyphrase/page to list if it doesn't exist
                    addKeyphrase(temp, temp2, page);

                    outerphrase[0] = '\0';
                    // continue adding letters to keyphrase while counter is 1
                } else if (counter == 1) {
                    strncat(outerphrase, &letter, 1);
                }
                // once close bracket is reached, add outer level keyphrase to list
                if (letter == ']' && counter == 2) {
                    counter--;
                    temp3 = innerphrase;
                    temp3.toLower();

                    addKeyphrase(temp, temp3, page);

                    innerphrase[0] = '\0';
                    // continue adding letters to keyphrase while counter is 1
                } else if (counter == 2) {
                    strncat(innerphrase, &letter, 1);
                    strncat(outerphrase, &letter, 1);
                }
            }
        } // eof is reached
        file.close();
    } // file closes
}
void IndexMaker::addKeyphrase(Stringy temp, Stringy temp2, char page[]){
    auto it = find(keyphrases.begin(), keyphrases.end(), Keyphrase(temp2));
    if (it != keyphrases.end()){
        // if it does exist, add page to Keyphrase object
        Vectory<Stringy>pages = it->getPage();
        auto it2 = find(pages.begin(), pages.end(), temp);
        if(it2 == pages.end())
            it->addPage(temp);
    }
    else
        // if it doesn't exist, add the keyphrase and page to list
        keyphrases.push_back(Keyphrase(page,temp2));
}
void IndexMaker::outputIndex(char outputFile[]){
    ofstream output(outputFile);
    // sort keyphrases alphabetically
    sort(keyphrases.begin(),keyphrases.end());

    // use iterator to output entire contents of keyphrase in nice format
    char firstLetter;
    for(auto it = keyphrases.begin(); it!=keyphrases.end();it++){
        if(firstLetter!=it->getFirstLetter())
            output<<"["<<it->getFirstLetter()<<"]"<<endl;
        firstLetter = it->getFirstLetter();

        output<<*it<<endl;
    }
}