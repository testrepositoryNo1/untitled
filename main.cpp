#include "main.h"

using namespace std;

/*
*
* Предполагается что в эту функцию передается предварительно отсортированный
* масив(вектор): [1...N + 1], в котором не хватает одного числа,
* функция находит данное число и выводит его на экран.
*
*/
void find_not_exist_var(vector<int> vec)
{
    int half_of_vec = vec.size() / 2;
    int not_exist = -1;

    while(vec.size() > 2) {
        if (vec.at(half_of_vec) != half_of_vec + vec.front() ) {
            vec.erase((vec.begin() + (half_of_vec + 1)), vec.end());
            half_of_vec = vec.size() / 2;
          }
        else {
            vec.erase(vec.begin(), (vec.begin() + half_of_vec));
            half_of_vec = vec.size() / 2;
          }
      }
    not_exist = (vec.front() + vec.back() ) / 2;
    cout << "not exist " << not_exist << endl;
}

int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    vector<int> main_vec;
    my_boost_int_Rnd rnd;
    int _rand = rnd.int_boost_rnd(1, 50000);
    cout << "r = " << _rand << endl;


    for (size_t i = 1; i < 50000; ++i)
      main_vec.push_back(i);

    auto pos = remove(main_vec.begin(), main_vec.end(), _rand);
    main_vec.erase(pos, main_vec.end());

    find_not_exist_var(main_vec);

//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}


