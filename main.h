#ifndef MAIN_H
#define MAIN_H
#include "stdfx.h"

template<class T>
void dre_gen(T &v, size_t _size, int _from, int _to)
{
    int seed = clock() * clock() / 3 ;
    default_random_engine dre(seed);
    uniform_int_distribution<int> di(_from, _to);
    for (size_t i = 0; i < _size; ++i)
      v.push_back(di(dre));

    for (auto a: v)
      cout << a << endl;
}

template <class T>
void print(const T &v)
{
    for (auto a: v)
      cout << a << " ";
    cout << endl;
}



#endif // MAIN_H
