#include "main.h"

using namespace std;


size_t strlenght(const char* str)
{
    const char* it = &str[0];
    size_t sz = 0;

    while(*it != '\0') {
            ++it;
            ++sz;
        }

    return sz;
}

char* revert(const char* str)
{
    char* rstr = new char [strlenght(str)];

    for (int i = strlenght(str) - 1, j = 0; i >= 0; --i, ++j) {
            rstr[j] = str[i];
        }
    return rstr;
}


int main ()
{
      Srand();
      ostream_iterator<int> out(cout, "\n");
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

      my_boost_int_Rnd rnd;

      char *str = new char [10];

      for (size_t i = 0; i < 10; ++i) {
              str[i] = static_cast<char>(rnd.int_boost_rnd(97, 122));
          }

      cout << str << endl;
      cout << revert(str) << endl;

      //cout << boost::typeindex::type_id_runtime(str).pretty_name() << endl;

//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}




