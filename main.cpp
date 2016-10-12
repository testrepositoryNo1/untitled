#include "main.h"

using namespace std;

template <class T>
void print(const T &v)
{
    for (auto a: v)
      cout << a << " - " << *a << endl;
}


int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    vector<int*> pvec;
    vector<int*> pvec1;

    shared_ptr<int> p(new int[10], default_delete<int>());

    auto ptr = p.get();

    for (int i = 0; i < 10; ++i) {
        *ptr = i;
        ++ptr;
        }

    ptr = p.get();

    for (int j = 0; j < 10; ++j, ++ptr) {
        pvec.push_back(ptr);
       }


    *(p.get() + 3) = 48;

    print(pvec);


//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms d = boost::chrono::duration_cast<ms>(end - start);
    double dd = d.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
    return 0;
}






