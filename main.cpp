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

//#include <thread>



using namespace std;
using namespace chrono;

template <typename T>
void func (vector<T> &v)
{
    generate(v.begin(), v.end(), rand);
}


template <typename T>
void show (vector<T> &v)
{
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
    cout << endl;
}

void sq (int &i)
{
    i = i * i;
}

int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, " ");
    clock_t start = clock();
//----------------------------------------------------------------

    vector<string> vec, vec1;
    size_t count = 0, i = 10;
    string str;

    while (i) {
        str = "";
        size_t x = rand()%10;
        int r = 0;

        if (x > 3) {
        while (x){
            r  = rand() %255;
            if ( (r >= 65 && r <= 90) || (r >= 97 && r <= 122)  || r == 32 ){
                str.push_back(char(r));
                --x;
            }
            else
                r = rand()%255;
        }
        ++count;
        vec1.push_back(str);
        str.erase( unique(str.begin(), str.end()), str.end() );
        vec.push_back(str);
        --i;
    }
        else x = rand()%10;
    }

    //copy(vec.begin(), vec.end(), vec1.begin());

    auto it = vec.begin();
    auto it1= vec1.begin();

    //for_each(vec1.begin(), vec1.end(), [](string &s) { reverse(s.begin(), s.end()); });

    vector<int> size;

    for (auto a : vec)
        size.push_back(a.size());

    auto max_elem = max_element(size.begin(), size.end());

    size_t max = *max_elem;


    for (; it != vec.end(); ++it, ++it1) {
        cout << setw(max) << *it << " - ";
        cout << *it1 << endl;

    }


//----------------------------------------------------------------
    clock_t finish = clock();
    double result = (finish - start) * 1.0 / CLOCKS_PER_SEC;
    cout << fixed << result << endl;
    return 0;
}





