#ifndef INC_21F_PA02__VECTORY_H
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
    Vectory();
    Vectory(const Vectory<T>&);
    Vectory<T>& operator=(const Vectory<T>&);
    ~Vectory();

    void push_back(const T&);
    const T& operator[](int);
    const T& at(int);
    void resize();
    int getSize();
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
    data[size++] = val;
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
int Vectory<T>::getSize() {
    return cap;
}

#endif
