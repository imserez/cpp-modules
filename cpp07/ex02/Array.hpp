#pragma once

#include <exception>
#include <cstddef>

template <typename T>
class Array {

    private:
        T* _vals;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &obj);
        ~Array();

        Array& operator=(const Array &obj);
        
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        unsigned int size(void) const;
        
        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Index is out of bounds";
                }
        };
};

template <typename T>
Array<T>::Array() : _vals(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _vals(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &obj) : _vals(NULL), _size(0) { *this = obj; }

template <typename T>
Array<T>::~Array() { delete[] _vals; }

template <typename T>
Array<T>& Array<T>::operator=(const Array &obj) {
    if (this != &obj) 
    {
        delete[] _vals;
        _size = obj._size;
        _vals = new T[_size]();
        
        for (unsigned int i = 0; i < _size; i++) {
            _vals[i] = obj._vals[i]; 
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw OutOfBoundsException();
    return _vals[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw OutOfBoundsException(); 
    return _vals[index];
}

template <typename T>
unsigned int Array<T>::size(void) const {
    return _size;
}