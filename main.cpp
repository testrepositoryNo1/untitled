#include "main.h"

using namespace std;

auto show_free_mem()
{
    system("free -h > .free.dat");
    ifstream fin(".free.dat", ios_base::in);
    vector<string> vec;
    vec.push_back("    ");

    string str;
    string matr[2][7];

    while (fin) {
            fin >> str;
            vec.push_back(str);
            str.clear();
        }
    fin.close();

    auto it = vec.begin();
    for (size_t i = 0; i < 2; ++i) {
            for (size_t j = 0; j < 7; ++j){
                    matr[i][j] = *it;
                    ++it;
                }
        }
    return matr[1][3];
}

class column_and_row
{
    int column;
    int row;
    int min;
public:
    column_and_row(){column = 0; row = 0; min = 0; }
    column_and_row(int c, int r) { column = c; row = r; }
    column_and_row(const column_and_row &col_and_row)
    {
        column = col_and_row.column; row = col_and_row.row; min = col_and_row.min;
    }

    column_and_row& operator=(const column_and_row &collrow) {
        column = collrow.column;
        row = collrow.row;
        min = collrow.min;
        return *this;
    }


    void set_cr(int c, int r, int m) { column = c; row = r; min = m; }
    void show_cr()
    {
        cout << "min:    " << min << endl;
        cout << "cloumn: " << column << endl;
        cout << "row:    " << row << endl;
    }
};


column_and_row find_min(int arr[10][10])
{
    int min = arr[0][0];
    column_and_row cr;

    for (size_t i = 0; i < 10; ++i) {
            for (size_t j = 0; j < 10; ++j) {
                    if (arr[i][j] < min) {
                      min = arr[i][j];
                      cr.set_cr((j + 1), (i + 1), min);
                      };
                }
        }
    return cr;
}




int main ()
{
      Srand();
      ostream_iterator<int> out(cout, "\n");
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

      my_boost_int_Rnd rnd;
      int arr[10][10];

      for (size_t i = 0; i < 10; ++i) {
              for (size_t j = 0; j < 10; ++j) {
                      arr[i][j] = rnd.int_boost_rnd(100, 300);
                  }
          }


      for (size_t i = 0; i < 10; ++i) {
              for (size_t j = 0; j < 10; ++j) {
                      cout << arr[i][j] << " ";
                  }
              cout << endl;
          }

      cout << "---------------------------------------------\n";

      column_and_row ab;

      ab = find_min(arr);

      ab.show_cr();




      //cout << boost::typeindex::type_id_runtime(elem).pretty_name() << endl;

//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}




