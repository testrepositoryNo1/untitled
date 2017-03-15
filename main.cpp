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


class TestClass
{
    int a;
    unique_ptr<int> p;
public:
    TestClass() : a{0}, p(new int(123)) { }
    TestClass(int r) : a{r} { }
    void operator =(TestClass &obj)
    {
        a = obj.a;
        p = move(obj.p);
    }

    ~TestClass()
    {
        //delete p; p = nullptr;
        cout << "destructor" << endl;
    }
    void show() const { cout << "show: " << a  << endl; }
};


/*
enum animal{dog, cat};

class PetShop
{
    uint   animal_age;
    bool   animal_sex; // true - boy, false - girl :-P
    double animal_coast;
    static size_t dog_count;
    static size_t cat_count;
    static int r;
public:
    PetShop() : animal_age{0}, animal_sex{true}, animal_coast{0.0} { }
    PetShop(animal _animal, uint _animal_age, bool _animal_sex, double _animal_coast);
    void sell(animal _animal, bool _animal_sex, double _animal_coast);
    void sell(animal _animal);
    void buy(animal _animal, uint _animal_age, bool _animal_sex, double _animal_coast);
    void show(animal _animal);
};

size_t PetShop::dog_count = 0;
size_t PetShop::cat_count = 0;

PetShop::PetShop(animal _animal, uint _animal_age, bool _animal_sex, double _animal_coast)
{
    if (_animal == animal::dog) {
            ++dog_count;
        }
    else {
            ++cat_count;
        }
    animal_age   = _animal_age;
    animal_sex   = _animal_sex;
    animal_coast = _animal_coast;
}

void PetShop::sell(animal _animal, bool _animal_sex, double _animal_coast)
{
    if (_animal == animal::dog) {
            --dog_count;
        }
    else {
           --cat_count;
        }
}

void PetShop::sell(animal _animal)
{
    if (_animal == animal::dog) {
            --dog_count;
        }
    else {
           --cat_count;
        }
}


void PetShop::show(animal _animal)
{
    if (_animal == animal::dog) {
            cout << "dog's age: " << animal_age << endl;
            cout << "      sex: ";
            if (animal_sex) {
                    cout << "boy" << endl;
                }
            else {
                    cout << "girl" << endl;
                }
            cout << "    coast: " << animal_coast << endl;
            cout << "     left: " << dog_count << endl;
            cout << "-------------------" << endl;
        }
    else {
            cout << "cat's age: " << animal_age << endl;
            cout << "      sex: " << animal_sex << endl;
            cout << "    coast: " << animal_coast << endl;
            cout << "     left: " << cat_count << endl;
            cout << "-------------------" << endl;
        }
}
*/


class Int
{
    unsigned int i;
public:
    Int() : i{0} {}
    Int(uint arg) { i = arg; }
    friend ostream& operator<<(ostream& os, const Int& obj);
    Int& operator=(const Int& right) {
            //проверка на самоприсваивание
            if (this == &right) {
                return *this;
            }
            i = right.i;
            return *this;
        }
    const Int operator+(const Int& rv) {
            return (i + rv.i);
        }
    /* перегрузкаа операторов для левого и правого операндов */
    friend Int operator+(const Int& lv, const int& rv)
    {
        return lv.i + rv;
    }
    friend Int operator+(const int& lv, const Int& rv)
    {
        return lv + rv.i;
    }

};

ostream& operator<<(ostream& os, const Int& obj)
{
    os << obj.i;
    return os;
}

class AA
{
    int i;
    int j;
    static int count;
public:
    AA () : i{count++}, j{0} { cout << "c = " << count << endl;
                         cout << "i = " << i << endl;
                   }
    AA (int arg) : i{count++}, j{arg} { cout << "c = " << count << endl;
                                        cout << "i = " << i << endl;
                                        cout << "j = " << j << endl;

                   }
    void show() const { cout << "c = " << count << endl;
                        cout << "i = " << i << endl;
                }
    AA test();
};

AA AA::test()
{
    AA tmp(150);
    return tmp;
}

int AA::count = 0;



int main ()
{
      Srand();
      boost::chrono::milliseconds start(clock());
///----------------------------------------------------------------



      Int a(1);
      Int b = 4;
      Int c = 2 + b;

      cout << c << endl;

     /* vector<AA> vec;

      for (size_t i = 0; i < 10; ++i) {
              vec.push_back(i);
          }
*/

/*      my_boost_int_Rnd rnd;

      vector<PetShop> dogs_base;

      for (size_t i = 0; i < 10; ++i) {
              dogs_base.push_back(PetShop(animal::dog, 1,
                                          rnd.int_boost_rnd(0,1),
                                          rnd.double_boost_rnd(500,600)));
          }


      auto iter = dogs_base.begin();

      for (;iter != dogs_base.end(); ++iter) {
              iter->show(animal::dog);
          }



      dogs_base.at(0).sell(animal::dog);
      dogs_base.at(0).show(animal::dog);

*/

      /* vector<int> vec;
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
*/
///---------------------------------------------------------------

      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}
