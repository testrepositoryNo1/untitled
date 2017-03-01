#include "main.h"

using namespace std;
ostream_iterator<int> out(cout, " ");


int find_the_index(const vector<int> &v, int _value)
{
    int index = 0;
    auto iter = find(v.begin(), v.end(), _value);
    auto beg = v.begin();

    if (iter != v.end()) {
            while (beg != iter) {
                    ++index;
                    ++beg;
                }
        };

    if (index >= 0)  return index;
    else return -1;
}



int main ()
{
      Srand();
      boost::chrono::milliseconds start(clock());
///----------------------------------------------------------------

      vector<int> vec;
      gen(vec, 100, 0, 100);
      my_boost_int_Rnd rnd;
      int elem = rnd.int_boost_rnd(0, 100);
      int index = find_the_index(vec, elem);
      auto iter = vec.begin();

      for (size_t i = 0; iter != vec.end(); ++i, ++iter) {
              cout << "index-" << i << " " << *iter << endl;
          }

      if (index == -1) {
              cout << "there is no element:" << elem << endl;
          }
      else {
              cout << "the index of " << elem << " is " << index << endl;
          }

///---------------------------------------------------------------

      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}
