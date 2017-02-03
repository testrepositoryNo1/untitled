#include "main.h"

using namespace std;


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
    uint show_y() { return y; }
    uint show_m() { return static_cast<uint>(m); }
    uint show_d() { return d; }
    void operator =(Date& a) { d = a.d; m = a.m; y = a.y; }
    friend ostream& operator<<(ostream& os, const Date& dt);

};

void Date::add_day(int n)
{
    d += n;
}

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.d << '.' << static_cast<int>(dt.m) << '.' << dt.y;
    return os;
}

int main ()
{
      Srand();
      ostream_iterator<string> out(cout, "\n");
      boost::chrono::milliseconds start(clock());
///----------------------------------------------------------------


      Date d(3, month_name::feb, 2017);
      Date s(7, month_name::nov, 2000);


      cout << d.show_d() << "." << d.show_m() << "." << d.show_y() << endl;


      cout << s << endl;
      cout << Date{12, month_name::dec, 2012} << endl;

      /*
      Date o;

      o.add_day(-7);

      cout << o.show_d() << "." << o.show_m() << "." << o.show_y() << endl;
*/
      //cout << boost::typeindex::type_id_runtime().pretty_name() << endl;

///---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}




