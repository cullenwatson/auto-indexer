#include "Stringy.h"

Stringy::Stringy() {
    str = new char[1];
    str[0] = '\0';
}
Stringy::Stringy(const char* s) {
    if (s == 0) {
        str = new char[1];
        str[0] = '\0';
    }
    else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}
Stringy::Stringy(const Stringy& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}
Stringy::~Stringy() {
    delete[]str;
    str = NULL;
}

Stringy& Stringy::operator= (const char* s) {
    delete[]str;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    return *this;
}
Stringy& Stringy::operator= (const Stringy& s) {
    if (this != &s) {
        delete[]str;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    return *this;
}
bool Stringy::operator< (const Stringy& s) const {
    return strcmp(str, s.str) < 0;
}
bool Stringy::operator< (const char* s) const {
    return strcmp(str, s) < 0;
}
bool Stringy::operator> (const Stringy& s) const {
    return strcmp(str, s.str) > 0;
}
bool Stringy::operator> (const char* s) const {
    return strcmp(str, s) > 0;
}
bool Stringy::operator== (const char* s) const {
    return strcmp(str, s) == 0;
}
bool Stringy::operator== (const Stringy& s) const {
    return strcmp(str, s.str) == 0;
}
Stringy Stringy::operator+ (const Stringy& s) {
    Stringy temp;
    temp.str = new char[strlen(str) + strlen(s.str) + 1];

    strcpy(temp.str, str);
    strcat(temp.str, s.str);

    return temp;
}
char& Stringy::operator[] (const int i) {
    // return first char if index is out of bounds
    if (i > strlen(str))
        return str[0];

    return str[i];
}
int Stringy::getLength() {
    return strlen(str);
}
Stringy Stringy::substring(int start, int numChars) {
    Stringy temp;
    // return empty string if index is out of bounds
    if (start > strlen(str) + 1 || start < 0)
        return temp;

    // return empty string if numChars is < 1
    if (numChars < 1)
        return temp;

    temp.str = new char[numChars + 1];

    for (int i = 0; i < numChars; i++)
        temp.str[i] = str[start + i];

    temp.str[numChars] = '\0';
    return temp;
}
char* Stringy::c_str() {
    return str;
}
std::ostream& operator<< (std::ostream& os, const Stringy& s) {
    os << s.str;
    return os;
}
std::istream& operator>> (std::istream& in, const Stringy& stringy) {
    in >> stringy.str;
    return in;
}

// return index if char exists
int Stringy::find(char chr) {
    char* ptr;
    ptr = strchr(str, chr);

    if (ptr != nullptr)
        return ptr - str;
    // return -1 if char not found
    return -1;
}
void Stringy::removeChar(char c) {
    // check if word is empty
    if (str == NULL)
        return;
    // create pointer that points to start of word
    char* result = str;
    char* wordPtr = str;

    // loop through every character in word
    while (*wordPtr) {
        // store letter in pointer value only if it is not the letter we're trying to remove
        if (*wordPtr != c) {
            *result = *wordPtr;
            result++;
        }
        // advance to next letter
        wordPtr++;
    }
    // add null character to end
    *result = '\0';
}
void Stringy::toLower() {
    for (int x = 0; x < strlen(str); x++) {
        str[x] = tolower(str[x]);
    }
}
void Stringy::toUpper() {
    for (int x = 0; x < strlen(str); x++) {
        str[x] = toupper(str[x]);
    }
}