#include "main.h"
#include <clocale>

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

template<typename T>
T fn(T&& x)
{
    cout << "x = " << x << endl;
    ++x;
    return x;
}


int main ()
{
      Srand();
      boost::chrono::milliseconds start(clock());
///----------------------------------------------------------------


      vector<char> chrvec{'a','b','c','d','e','f',
                          'g','h','i','j','k','l',
                          'm','n','o','p','q','r','s',
                          't','u','v','w','x','y','z'};


      ifstream fin("nounlist.txt", ios_base::in);
      string str;

      vector<string> svec;

      while (fin) {
             getline(fin, str);
             svec.push_back(str);
             str.clear();
          }


      string frst = "man";

      string lst = "war";



      vector<string> svec2;
      ofstream fout("results.txt", ios_base::out);

      for (auto elem : svec) {
              if (elem.size() == frst.size()) {
                      svec2.push_back(elem);
                      fout << elem << endl;
                  }
          }
      fout.close();


      vector<string> stack;
      stack.push_back(frst);
      string tmp = frst;


 /*     for (auto it = svec2.begin(); it != svec2.end(); ++it) {
              for (int i = frst.size() - 1; i >= 0; --i) {
                      tmp = stack.back();
                      for (size_t j = 0; j < chrvec.size(); ++j) {
                              tmp.at(i) = chrvec.at(j);
                              auto it = find(svec2.begin(),svec2.end(), tmp);
                              if (it != svec2.end() && tmp != frst) {
                                   stack.push_back(tmp);
                                  };
                              if (tmp == lst) break;
                          }
                      if (tmp == lst) break;
                  }
              if (tmp == lst) break;
          }

      for (auto elem : stack) {
              cout << elem << endl;
          }
*/


      while(tmp != lst) {
              for (auto it = svec2.begin(); it != svec2.end(); ++it) {
                      for (int i = frst.size() - 1; i >= 0; --i) {
                              tmp = stack.back();
                              for (size_t j = 0; j < chrvec.size(); ++j) {
                                      tmp.at(i) = chrvec.at(j);
                                      auto it = find(svec2.begin(),svec2.end(), tmp);
                                      if (it != svec2.end() && tmp != frst) {
                                           stack.push_back(tmp);
                                           cout << tmp << endl;
                                          };
                                      if (tmp == lst) break;
                                  }
                              if (tmp == lst) break;
                          }
                      if (tmp == lst) break;
                  }
          }


      fin.close();
      fout.close();


///---------------------------------------------------------------

      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}




