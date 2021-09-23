#ifndef INC_21F_PA02_STRINGY_H
#define INC_21F_PA02_STRINGY_H
#pragma warning(disable : 4996) // remove in clion

#include <iostream>
#include <cstring>

class Stringy
{
private:
    char* str;
public:
    // constructors
    Stringy();
    Stringy(const char*);
    Stringy(const Stringy&);
    ~Stringy();

    // overloaded assignment operators
    Stringy& operator= (const char*);
    Stringy& operator= (const Stringy&);

    // overloaded relational operators
    bool operator< (const Stringy&) const;
    bool operator< (const char*) const;
    bool operator> (const Stringy&) const;
    bool operator> (const char*) const;
    bool operator== (const char*) const;
    bool operator== (const Stringy&) const;

    // string concat
    Stringy operator+ (const Stringy&);

    // access particular character
    char& operator[] (const int);

    int getLength();
    Stringy substring(int start, int numChars);
    // returns null-terminated c-string holding contents of this object
    char* c_str();

    // send contents to output/input stream
    friend std::ostream& operator<< (std::ostream&, const Stringy&);
    friend std::istream& operator>> (std::istream&, const Stringy&);

    // see if char exists
    int find(char chr);

    // remove a character from stringy
    void removeChar(char);

    // convert string to upper or lowercase
    void toLower();
    void toUpper();
};

#endif //INC_21F_PA02_STRINGY_H