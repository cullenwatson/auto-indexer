#ifndef INC_21F_PA02_KEYPHRASE_H
#define INC_21F_PA02_KEYPHRASE_H

#include"Stringy.h"
#include"Vectory.h"
using namespace std;
class Keyphrase {
    Vectory<Stringy> Page;
    Stringy Phrase;
public:
    Keyphrase();
    Keyphrase(Stringy, Stringy);
    Keyphrase(Stringy);
    Vectory <Stringy> getPage();
    Stringy getPhrase();
    void addPage(Stringy);
    bool operator==(const Keyphrase&) const;
    bool operator<(const Keyphrase&) const;
    friend ostream& operator<< (ostream&, const Keyphrase&);

    char getFirstLetter();
};


#endif
