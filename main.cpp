#include "main.h"
using namespace std;

template <class T>
void print(const T &v)
{
    for (auto a: v)
      cout << a << " ";
    cout << endl;
}


int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    clock_t start = clock();
//----------------------------------------------------------------

    vector<int> vec;
    my_boost_int_Rnd object;

    for (size_t i = 0; i < 10; ++i)
      vec.push_back(object.boost_rnd(-1789, 1));


    for(auto a: vec)
      cout << a<< endl;

//---------------------------------------------------------------
    clock_t finish = clock();
    double result = (finish - start) * 1.0 / CLOCKS_PER_SEC;
    cout << fixed << result << endl;
    return 0;
}






