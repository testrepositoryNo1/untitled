#include "main.h"

using namespace std;
ostream_iterator<int> out(cout, " ");


enum class month_name
{
    jan = 1, feb, mar, apr, may,june, jul,aug, sem, nov, oct, dec
};

class Date
{
    uint y;
    month_name m;
    uint d;
public:
    Date() : y{1}, m{month_name::jan}, d{1} { y = 2017; m = month_name::jan; d = 9;}
    Date(uint dd, month_name mm, uint yy) { y = yy, m = mm, d = dd; }

    void add_day(int n);
    uint show_y() const { return y; }
    uint show_m() const { return static_cast<uint>(m); }
    uint show_d() const { return d; }
    void operator =(Date& a) { d = a.d; m = a.m; y = a.y; }
    friend ostream& operator<<(ostream& os, const Date& dt);

};

void Date::add_day(int n)
{
    if(n >= 1 && n <= 31) {
            d += n;
        }
}

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.d << '.' << static_cast<int>(dt.m) << '.' << dt.y;
    return os;
}

void f(int *r, size_t sz)
{
    for (size_t i = sz / 2; i < sz; ++i) {
           r[i] = i*i;
        }
}


class Class_1
{
public:
    int i;
    Class_1() : i{0} {}
    virtual void show(int x)
    {
        cout << "Class_1 " << x << endl;
    }
    virtual ~Class_1() { cout << "Class_1 destructor" << endl; }
};


class Class_2 : public Class_1
{
public:
    void show(int x)
    {
        cout << "Class_2 " << x << endl;
    }
    ~Class_2() { cout << "Class_2 destructor" << endl; }
};

class Class_3 : public Class_1
{
public:
    void show(int x)
    {
        cout << "Class_3 " << x << endl;
    }
    ~Class_3() { cout << "Class_3 destructor" << endl; }
};

template <typename T>
void f(T&& arg)
{
    copy(arg.begin(), arg.end(), out);
    cout << endl;
}


template <typename T>
void f(T&& arg, int x)
{
    *arg.begin() = x;
    copy(arg.begin(), arg.end(), out);
    cout << endl;
}


int main ()
{
      Srand();
      boost::chrono::milliseconds start(clock());
///----------------------------------------------------------------

      while (true) {

      string pwd = "";

      cout << "Вводите пароль: ";
      cin >> pwd;


      string find_the_match = "";
      size_t count = 0;
      vector<char> ch_vec {'a','b','c','d','e','f',
                           'g','h','i','j','k','l',
                           'm','n','o','p','q','r',
                           's','t','u','w','x','y','z',
                           48,49,50,51,52,53,54,55,56,57,
                           'A','B','B','B','E','F',
                           'G','G','G','J','K','L',
                           'M','N','O','P','Q','R',
                           'S','T','U','W','X','Y','Z',
                           '~','!','@','#','$','%','^','&','*','(',')','+','=','[',']','{','}'};



      size_t max_size = 3; /* max elements */
      size_t tryes = 1;
      size_t sz_for_str = 1;
      bool _break = false;


      for (; tryes <= max_size; ++tryes) {
              switch (tryes) {
                  case 1:
                      for (auto it = ch_vec.begin(); it != ch_vec.end(); ++it) {
                              find_the_match = *it;
                              ++count;
                              if (find_the_match == pwd) {
                                      cout << "find: " << find_the_match
                                           << " after " << count << " tryes" << endl;
                                      _break = true;
                                      tryes = max_size;
                                      break;
                                  };
                              if (find_the_match == "}" && find_the_match != pwd) {
                                      _break = true;
                                      break;
                                  };
                          } if (_break) break;
                  case 2:
                      _break = false;
                      sz_for_str = 2;
                      while (!_break) {
                              vector<char>::iterator iter1 = ch_vec.begin();
                              vector<char>::iterator iter2 = ch_vec.begin();
                              find_the_match.clear();
                              find_the_match.shrink_to_fit();
                              find_the_match.resize(sz_for_str);
                              size_t i = sz_for_str - 2;
                              for (; iter1 != ch_vec.end(); ++iter1) {
                                      find_the_match.at(i) = *iter1;
                                      iter2 = ch_vec.begin();
                                      ++count;
                                      for (size_t j = i + 1; iter2 != ch_vec.end(); ++iter2) {
                                              find_the_match.at(j) = *iter2;
                                              ++count;
                                              if (find_the_match == pwd) {
                                                      cout << "find: " << find_the_match
                                                           << " after " << count << " tryes" << endl;
                                                      _break = true;
                                                      tryes =  max_size;
                                                      break;
                                                  };
                                              if (find_the_match == "}}" && find_the_match != pwd) {
                                                         _break = true;
                                                  };
                                          }
                                  }
                          } if (_break) break;
                  case 3:
                      _break = false;
                      sz_for_str = 3;
                      while (!_break) {
                              vector<char>::iterator iter1 = ch_vec.begin();
                              vector<char>::iterator iter2 = ch_vec.begin();
                              vector<char>::iterator iter3 = ch_vec.begin();
                              find_the_match.clear();
                              find_the_match.shrink_to_fit();
                              find_the_match.resize(sz_for_str);
                              size_t i = sz_for_str - 3;
                              ++count;
                              for (; iter1 != ch_vec.end(); ++iter1) {
                                      find_the_match.at(i) = *iter1;
                                      iter2 = ch_vec.begin();
                                      ++count;
                                      for (size_t j = i + 1; iter2 != ch_vec.end(); ++iter2) {
                                              find_the_match.at(j) = *iter2;
                                               iter3 = ch_vec.begin();
                                               ++count;
                                               for (size_t k = j + 1; iter3 != ch_vec.end(); ++iter3) {
                                                       find_the_match.at(k) = *iter3;
                                                       ++count;
                                                       if (find_the_match == pwd) {
                                                               cout << "find: " << find_the_match
                                                                    << " after " << count << " tryes" << endl;
                                                               _break = true; break;
                                                           };
                                                       if (find_the_match == "}}}" && find_the_match != pwd) {
                                                                  _break = true;
                                                           };
                                                   }
                                               if (_break) break;
                                          }
                                      if (_break) break;
                                  }

                          } break;
                  }
          }

      cout << "--------------------------\n";


}

      /*bool _break = false, _continue = false;

      while (!_break) {
              vector<char>::iterator iter = ch_vec.begin();
              for (; iter != ch_vec.end(); ++iter) {
                      find_the_match = *iter;
                      if (find_the_match == pwd) {
                              _break    = true;
                              _continue = false;
                              break;
                          }
                      else {
                              ++count;
                              if (count > ch_vec.size()) {
                                      _break    = true;
                                      _continue = true;
                                  };
                          }
                  }
          }

      if (_continue) {
              _break = false;
              static size_t sz_for_str = 2;
              while (!_break) {
                      vector<char>::iterator iter1 = ch_vec.begin();
                      vector<char>::iterator iter2 = ch_vec.begin();
                      find_the_match.clear();
                      find_the_match.shrink_to_fit();

                      find_the_match.resize(sz_for_str);
                      size_t i = sz_for_str - 2;
                      for (; iter1 != ch_vec.end(); ++iter1) {
                              find_the_match.at(i) = *iter1;
                              iter2 = ch_vec.begin();
                              for (size_t j = i + 1; iter2 != ch_vec.end(); ++iter2) {
                                      find_the_match.at(j) = *iter2;
                                      if (find_the_match == pwd) {
                                              _break = true; break;
                                          }
                                      else {
                                              ++count;
                                          }
                                  }
                              if (_break) break;
                          }
                  }
          };

      cout << "we found the password: " << find_the_match
           << " after " << count  << " tryes!" << endl;

*/

      /*
      Class_1* obj_1 = new Class_1;
      Class_2* obj_2 = new Class_2;
      Class_3* obj_3 = new Class_3;

      delete obj_2;
      */
///---------------------------------------------------------------

      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}




