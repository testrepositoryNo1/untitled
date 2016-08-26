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
#include <list>
#include <set>

#include <memory>


#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string.h>

using namespace std;

template <class T>
void gen(T &v, size_t size)
{
    int r = 0;
    while (size) {
        r = rand()%10;
       v.push_back(r);
       --size;
    }
}

template <class T>
void print(const T &v)
{
    copy(v.begin(), v.end(),ostream_iterator<int>(cout, " "));
}

int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, " ");
    clock_t start = clock();
//----------------------------------------------------------------

    vector<int> vec;
    gen(vec, 10);

    sort(vec.begin(), vec.end());


    print(vec);
    cout << endl;

//----------------------------------------------------------------
    clock_t finish = clock();
    double result = (finish - start) * 1.0 / CLOCKS_PER_SEC;
    cout << fixed << result << endl;
    return 0;
}





