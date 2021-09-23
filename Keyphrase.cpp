#include "Keyphrase.h"
Keyphrase::Keyphrase(){
    Phrase="";
}
Keyphrase::Keyphrase(Stringy page, Stringy phrase){
    Page.push_back(page);
    Phrase = phrase;
}

Keyphrase::Keyphrase(Stringy phrase){
    Phrase = phrase;
}
Vectory<Stringy> Keyphrase::getPage(){
    return Page;
};
Stringy Keyphrase::getPhrase(){
    return Phrase;
};
void Keyphrase::addPage(Stringy page){
    Page.push_back(page);
}
bool Keyphrase::operator==(const Keyphrase& obj2) const {
    if (this->Phrase == obj2.Phrase)
        return true;
    else
        return false;
}

bool Keyphrase::operator<(const Keyphrase &obj) const {
    return Phrase < obj.Phrase;
}

ostream &operator<<(ostream & os, const Keyphrase & keyphrase) {

    os<<keyphrase.Phrase<<": ";

    for(int i=0; i<keyphrase.Page.getSize();i++){
        os<<keyphrase.Page[i];
        if(i!=keyphrase.Page.getSize()-1)
            cout<<", ";
    }
    return os;
}

char Keyphrase::getFirstLetter() {
    Stringy temp = Phrase;
    temp.toUpper();
    return temp[0];
}
