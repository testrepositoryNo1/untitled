#include "main.h"

using namespace std;

class Date
{
public:
    unsigned day;
    unsigned month;
    unsigned year;
public:
    Date(string str) { get_date_sring(str); }
    ~Date() {}
    void get_date_sring(string str);
};

void Date::get_date_sring(string str)
{
    string temp1, temp2, temp3;

    for  (size_t i = 0, j = 3, k = 6; i < 2; ++i, ++j, ++k) {
            temp1 += str.at(i);
            temp2 += str.at(j);
            temp3 += str.at(k);
        }
    day   = stoi(temp1, 0, 10);
    month = stoi(temp2, 0, 10);
    year  = stoi(temp3, 0, 10);
}


void sort_the_date(vector<Date> &data_vec);


bool cmp_dates_up(const Date& d1, const Date& d2) {
    return (d1.year < d2.year)  ||
           (d1.year == d2.year && d1.month < d2.month) ||
           (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day);
}
bool cmp_dates_down(const Date& d1, const Date& d2) {
    return (d1.year > d2.year)  ||
           (d1.year == d2.year && d1.month > d2.month) ||
           (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day);
}



int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    boost::filesystem::ifstream fin;
    boost::filesystem::ofstream fout;

    fin.open("SuperBackup", ios::in);
    fout.open("SuperBackup_", ios::out);

    vector<string> svec;
    string str, temp;


    while (fin) {
            getline(fin, str);
            svec.push_back(str);
            str.clear();
        }
    auto it = svec.begin();
    for (; it != svec.end(); ++it) {
            auto pos1 = it->find("body=") + 15;
            auto pos2 = it->find("р\"");
            if (pos1 != string::npos && pos2 != string::npos) {
                while (pos1 != pos2) {
                      fout << it->at(pos1);
                      ++pos1;
                    }
                fout << "\n";
                }
        }
    svec.clear();
    fin.close();
    fout.close();

    fin.open("SuperBackup_", ios::in);
    fout.open("temp.txt", ios::out);

    while (fin) {
            getline(fin, str);
            svec.push_back(str);
            str.clear();
        }

    vector<string> date_vec;

    svec.pop_back();
    it = svec.begin();
    for (; it != svec.end(); ++it) {
            size_t i = 0;
            while (i < 8) {
                    str += it->at(i);
                    ++i;
                    }
            date_vec.push_back(str);
            str.clear();
                }

    fin.close();
    fout.close();

    vector<Date> dvec;

    for (auto a : date_vec)
        dvec.push_back(a);


    sort(dvec.begin(), dvec.end(), cmp_dates_down);


    for(auto a : dvec)
        cout << a.day << "."
             << a.month << "." << a.year << endl;




//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}


