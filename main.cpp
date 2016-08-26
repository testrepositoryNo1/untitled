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
void gen(T &v)
{
    int r = 0;
    size_t size = 10;
    while (size) {
        r = rand()%1000;
       v.push_back(r);
       --size;
    }
}

template <class T>
void print(const T &v)
{
    auto it = v.begin();

    for (; it != v.end(); ++it)
        cout << *it << " - " << &(*it) << endl;
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
    gen(vec);

    auto x = max_element(vec.begin(), vec.end());
    print(vec);
    cout << "max: " << *x << " - " << &(*x) <<endl;

    sort(vec.begin(), vec.end()); /* порядок элементов меняется в ходе сортировки но адреса нет,
                                    и адрес который получила переменная x указывает на другой элемент (со списком такого не возникает)*/

    x = max_element(vec.begin(), vec.end()); /* для коректного отображения максимального элемента */
    print(vec);
    cout << "max: " << *x << " - " << &(*x) << endl;

//----------------------------------------------------------------
    clock_t finish = clock();
    double result = (finish - start) * 1.0 / CLOCKS_PER_SEC;
    cout << fixed << result << endl;
    return 0;
}





