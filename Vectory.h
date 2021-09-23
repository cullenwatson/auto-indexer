#ifndef INC_21F_PA02_VECTORY_H
#define INC_21F_PA02_VECTORY_H
#include<iostream>
using namespace std;
template<typename T>
class Vectory
{
    T* data;
    int size;
    int cap;
public:
    // rule of three
    Vectory();
    Vectory(const Vectory<T>&);
    Vectory<T>& operator=(const Vectory<T>&);
    ~Vectory();

    // resize vector
    void push_back(const T&);
    void pop_back();
    void resize();

    // get elements & properties of vector
    const T& operator[](int) const;
    const T& at(int);
    int getSize() const;
    int getArraySize();

    // basic iterator functionality
    typedef T* iterator;

    iterator begin(){
        return data;
    }

    iterator end(){
        return data + cap;
    }
};

// default constructor, sets size to 10
template<typename T>
Vectory<T>::Vectory() {
    size = 10;
    cap = 0;
    data = new T[size];

}
// copy constructor
template<typename T>
Vectory<T>::Vectory(const Vectory<T>& copy) {
    cap = copy.cap;
    size = copy.size;
    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = copy.data[i];
}
// assignment operator
template<typename T>
Vectory<T>& Vectory<T>::operator=(const Vectory<T>& copy) {
    // checks if addresses are not equal before deleting
    if (this != &copy) {
        delete[]data;
        cap = copy.cap;
        size = copy.size;
        data = new T[size];

        // copy the data
        for (int i = 0; i < size; i++)
            data[i] = copy.data[i];

    }
    return *this;
}
// destructor
template<typename T>
Vectory<T>::~Vectory() {
    delete[]data;
}
// add elements
template<typename T>
void Vectory<T>::push_back(const T& val) {
    // resizes vector if it's full
    if (size == cap)
        resize();

    data[cap++] = val;
}
// remove last element
template<typename T>
void Vectory<T>::pop_back() {
    // check if element exists
    if (cap > 0)
        cap--;
}
// access an element
template<typename T>
const T& Vectory<T>::operator[](int loc) const{
    // check the index
    if (loc < 0 || loc > size - 1)
        throw "Index out of bounds";
    return data[loc];
}
// access an element
template<typename T>
const T& Vectory<T>::at(int loc) {
    // check the index
    if (loc < 0 || loc > size - 1)
        throw "Index out of bounds";
    return data[loc];
}
// resize array if full
template<typename T>
void Vectory<T>::resize() {
    // makes new array twice the size
    T* temp = new T[size * 2];
    // assigns the data from old to new array
    for (int i = 0; i < size; i++)
        temp[i] = data[i];

    // update size and delete old data
    size *= 2;
    delete[]data;
    data = temp;
}
// get the size that the user has used
template<typename T>
int Vectory<T>::getSize() const {
    return cap;
}
// get the size of the arrazy
template<typename T>
int Vectory<T>::getArraySize(){
    return size;
}

#endif