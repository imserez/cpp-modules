#pragma once

template <typename T, typename Func>
void    iter(T *arrptr, const int len, Func f)
{
    for (int i = 0; i < len; i++)
    {
        f(arrptr[i]);
    }
}