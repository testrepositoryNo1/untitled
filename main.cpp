
#include "stdfx.h"
using namespace std;

template <class T>
void gen(T &v, size_t size, unsigned int modulo)
{
  if (modulo > 1) {
  int r = 0;
    while (size) {
        r = rand() % modulo;
       v.push_back(r);
       --size;
    }
    }
  else {
      cout << "modulo must be more or equal 2" << endl;
      exit(0);
    }
}

template <class T>
void gen_(T &v, size_t size, int from)
{
    while (size) {
        v.push_back(from);
        ++from;
        --size;
      }
}



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



//---------------------------------------------------------------
    clock_t finish = clock();
    double result = (finish - start) * 1.0 / CLOCKS_PER_SEC;
    cout << fixed << result << endl;
    return 0;
}






