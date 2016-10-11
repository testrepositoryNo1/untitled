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
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------


    vector<int> vec;
    for (int i = 0; i < 10000; ++i )
        vec.push_back(i);





//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms d = boost::chrono::duration_cast<ms>(end - start);
    double dd = d.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
    return 0;
}






