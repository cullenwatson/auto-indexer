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
    const T& operator[](int);
    const T& at(int);
    int getSize() const;
    int getArraySize();

    typedef T* iterator;

    iterator begin(){
        return data;
    }

    iterator end(){
        return data + cap;
    }
};


template<typename T>
Vectory<T>::Vectory() {
    size = 10;
    cap = 0;
    data = new T[size];

}
template<typename T>
Vectory<T>::Vectory(const Vectory<T>& copy) {
    cap = copy.cap;
    size = copy.size;
    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = copy.data[i];
}
template<typename T>
Vectory<T>& Vectory<T>::operator=(const Vectory<T>& copy) {
    if (this != &copy) {
        delete[]data;
        cap = copy.cap;
        size = copy.size;
        data = new T[size];

        for (int i = 0; i < size; i++)
            data[i] = copy.data[i];

    }
    return *this;
}
template<typename T>
Vectory<T>::~Vectory() {
    delete[]data;
}
template<typename T>
void Vectory<T>::push_back(const T& val) {
    if (size == cap)
        resize();
    data[cap++] = val;
}
template<typename T>
void Vectory<T>::pop_back() {
    if (cap > 0)
        cap--;
}
template<typename T>
const T& Vectory<T>::operator[](int loc) {
    if (loc < 0 || loc > size - 1)
        throw "Index out of bounds";
    return data[loc];
}
template<typename T>
const T& Vectory<T>::at(int loc) {
    if (loc < 0 || loc > size - 1)
        throw "Index out of bounds";
    return data[loc];
}
template<typename T>
void Vectory<T>::resize() {
    T* temp = new T[size * 2];
    for (int i = 0; i < size; i++)
        temp[i] = data[i];

    size *= 2;
    delete[]data;
    data = temp;
}
template<typename T>
int Vectory<T>::getSize() const {
    return cap;
}
template<typename T>
int Vectory<T>::getArraySize(){
    return size;
}

#endif