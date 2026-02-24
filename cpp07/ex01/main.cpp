#include "iter.hpp"


#include <iostream>


template <typename T>
void increment(T &element) 
{
    ++element;
}

template <typename T>
void print_el(const T &element) 
{
    std::cout << element << " ";
}


template <typename T>
void print_arr(T &arr, int len)
{
    for(int i = 0; i<len;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(void)
{

    int len = 5;
    int arr[] = {0, 10, 30, 50, 100};
    print_arr(arr, len);
    ::iter(arr, len, increment<int>);
    print_arr(arr, len);

    char arr2[] = {'a', 'b', 'c', 'd', 'e'};
    print_arr(arr2, len);
    ::iter(arr2, len, increment<char>);
    print_arr(arr2, len);
    
    const double arr3[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    ::iter(arr3, len, print_el<double>);
    std::cout << std::endl;
}