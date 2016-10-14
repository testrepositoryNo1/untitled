#include "main.h"

using namespace std;

template <class T>
void print(const T &v)
{
    for (auto a: v)
      cout << a << endl;
}



int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    int x = 98;
    vector<int> vec(10,77);
    my_boost_int_Rnd rnd;

    generate(vec.begin(), vec.end(), [&vec, &rnd](){
        return rnd.int_boost_rnd(0, 100);
      });


    print(vec);

//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms d = boost::chrono::duration_cast<ms>(end - start);
    double dd = d.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
    return 0;
}






