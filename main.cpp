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
    my_boost_int_Rnd rnd;
    vector<int> vec;
    for(size_t i = 0; i < 10; ++i)
      vec.push_back(rnd.int_boost_rnd(0,100));

    for (auto a: vec)
      cout << a << endl;

    auto iter = find_if(vec.begin(), vec.end(),
                        [](int var) {  return var==50; });

    if(iter != vec.end())
      cout << "---------------\n" << distance(vec.begin(), iter) << endl;
    else
      cout<< "no matches for " << 50 << endl;






/*
    list<int> lst;
    vector<int*> pvec;

    for (int i = 0; i < 20; ++i)
      lst.push_back(i);

    auto it = lst.begin();
    for (; it != lst.end(); ++it ) {
        pvec.push_back(&(*it));
       }


    print(pvec);

*/
//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms d = boost::chrono::duration_cast<ms>(end - start);
    double dd = d.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
    return 0;
}






