#include "main.h"

using namespace std;

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
    boost::chrono::microseconds start(clock());
//----------------------------------------------------------------

/*
    vector<int> vec;
    for (int i = 0; i < 1000; ++i )
        vec.push_back(i);

    my_boost_int_Rnd rnd;
*/
    shared_ptr<string> s1Ptr(new string ("test"));
    shared_ptr<string> s2Ptr(new string("this"));

    (*s1Ptr)[0] = 'T';
    s2Ptr->replace(0, 1, "T");

    vector<shared_ptr<string>> spvec;

    spvec.push_back(s1Ptr);
    spvec.push_back(s2Ptr);
    spvec.push_back(s1Ptr);
    spvec.push_back(s2Ptr);
    spvec.push_back(s1Ptr);
    spvec.push_back(s2Ptr);

    for (auto ptr: spvec)
        cout << *ptr << endl;

    *s1Ptr = "understand";

    for (auto ptr: spvec)
        cout << *ptr << endl;



//---------------------------------------------------------------
    boost::chrono::microseconds end(clock());
    using ms = boost::chrono::microseconds;
    ms d = boost::chrono::duration_cast<ms>(end - start);
    double dd = d.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
    return 0;
}






