#include <iostream>
#include <iomanip>
#include <stdio.h>

//#include <ctime>
//#include <time.h>
#include <chrono>

#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <string>
#include <utility>
//#include <deque>
//#include <list>
//#include <set>
#include <stack>
#include <queue>

#include <memory>
#include <cassert>

#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string.h>

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

    size_t count = 0;
    string str, rand_word = "test" ;
    size_t x = 0;
    int r = 0;


    while (str != rand_word) {
            str = "";
            x = rand()%10;
            if (x == rand_word.size()) {
            while (x){
                r  = rand() %255;
                if ( (r >= 65 && r <= 90) || (r >= 97 && r <= 122)  || r == 32 ){
                    str.push_back(char(r));
                    --x;
                  }
              }
          }
            ++count;
      }

    cout << str << " - " << count << endl;


//---------------------------------------------------------------
    clock_t finish = clock();
    double result = (finish - start) * 1.0 / CLOCKS_PER_SEC;
    cout << fixed << result << endl;
    return 0;
}






