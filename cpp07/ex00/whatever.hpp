#pragma once

template <typename T>
void swap(T &obj1, T &obj2)
{
    T temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

template <typename T>
const T& min(const T &obj1, const T &obj2)
{
    if (obj1 < obj2)
        return obj1;
    return obj2;
}

template <typename T>
const T& max(const T &obj1, const T &obj2)
{
    if (obj1 > obj2)
        return obj1;
    return obj2;
}