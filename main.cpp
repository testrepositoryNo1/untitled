#include "main.h"

using namespace std;
#define REMOVE "rm -rf a b c d e f g h i j k l m n o p q r s t u v w x y z"

template <class T>
void print(const T &v)
{
    for (auto a: v)
      cout << a << endl;
}

void scatter_to_alphabet()
{
  ofstream fout;
  ifstream fin("text.txt");
  char ch = 'a';
  string str = "";

  for (int i = 0; i < 25; ++i) {
      str = ch;
      fout.open(str.data());
      fout.close();
      ++ch;
    }

  string temp = "";
  ch = 'a';

  while(fin) {
      fin >> temp;
      if(!temp.empty()) {
      switch (temp.at(0)) {
        case 'a':
          fout.open("a", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'b':
          fout.open("b", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'c':
          fout.open("c", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'd':
          fout.open("d", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'e':
          fout.open("e", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'f':
          fout.open("f", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'g':
          fout.open("g", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'h':
          fout.open("h", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'i':
          fout.open("i", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'j':
          fout.open("j", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'k':
          fout.open("k", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'l':
          fout.open("l", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'm':
          fout.open("m", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'n':
          fout.open("n", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'o':
          fout.open("o", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'p':
          fout.open("p", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'q':
          fout.open("q", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'r':
          fout.open("r", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 's':
          fout.open("s", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 't':
          fout.open("t", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'u':
          fout.open("u", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'v':
          fout.open("v", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'w':
          fout.open("w", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'x':
          fout.open("x", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'y':
          fout.open("y", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
        case 'z':
          fout.open("z", ios::app);
          fout << temp << endl;
          temp.clear();
          fout.close(); break;
      }
    }
  }
}

void sort_the_file(string _name)
{
  ifstream fin(_name.data());

  multiset<string> mset_str;
  string str = "";

  while (fin) {
      fin >> str;
      mset_str.insert(str);
      str.clear();
    }
  fin.close();

  string _name_tmp = _name + ".tmp";


  ofstream fout(_name_tmp.data(), ios::app);

  auto iter = mset_str.begin();
  ++iter;

  for (; iter != mset_str.end(); ++iter)
    fout << *iter << endl;

  fout.close();

 /*--- deleting not sorted source files---*/
  string tmp = "rm -rf " + _name;
  system(tmp.data());
  tmp = "mv " + _name_tmp + " " + _name;
  system(tmp.data());
  /*--- ---*/
}

void _union()
{
  ofstream fout("union.txt");
  ifstream fin;

  char ch = 'a';
  string str = "", temp = "";
  str += ch;

  for(size_t i = 0; i <= 25; ++i) {
     fin.open(str);
      while (fin) {
       fin >> temp;
       fout << temp << endl;
       temp.clear();
       }
      fin.close();
      ++ch;
      str = ch;
    }
  fout.close();
}

int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    /*
       size_t c = 100000
        ;
    size_t r = 0;
    string str = "";

    my_boost_int_Rnd rnd;

    ofstream fout;
    fout.open("text.txt");

    while (c) {
        r = rnd.int_boost_rnd(3, 8);
        for (size_t i = 0; i < r; ++i) {
            str += static_cast<char>(rnd.int_boost_rnd(97, 122));
          }
        fout << str << " ";
        str.clear();
        --c;
      }
    fout.close();
    */

    system(REMOVE);
    scatter_to_alphabet();

    char ch = 'a';
    string str = "";
    str += ch;

    for(size_t i = 0; i <= 25; ++i) {
        sort_the_file(str);
        ++ch;
        str = ch;
      }
    _union();


//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
    return 0;
}






