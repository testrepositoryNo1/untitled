#include "main.h"

using namespace std;

template <class T>
void print(const T &v)
{
    for (auto a: v)
      cout << a << endl;
}

int func()
{
  return 987;
}


int run(int arg);

int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    boost::circular_buffer<int> cbuf{3};

    cbuf.push_back(1);
    cbuf.push_back(2);
    cbuf.push_back(3);

    auto it = cbuf.begin();

    for (; it != cbuf.end(); ++it)
      cout << *it << " - " << &(*it) << endl;

    cbuf.push_back(4);

    cout << " ----- " << endl;

    it = cbuf.begin(); /* statart all over for iterator */

    for (; it != cbuf.end(); ++it)
      cout << *it << " - " << &(*it) << endl;

    cbuf.push_back(5);

    cout << " ----- " << endl;

    it = cbuf.begin(); /* statart all over for iterator */

    for (; it != cbuf.end(); ++it)
      cout << *it << " - " << &(*it) << endl;




//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
    return 0;
}






