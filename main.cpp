#include "main.h"

using namespace std;

class Date
{
public:
    unsigned day;
    unsigned month;
    unsigned year;
    Date() { day = 0; month = 0; year = 0;}
    Date(string str) { get_date_sring(str); }
    ~Date() {}
    void get_date_sring(string str);
    friend ostream& operator<<(ostream& os, const Date& dt);
//    Date operator ()(Date dt1, Date dt2) {}
    int operator <(Date dt);
    void show() { cerr << "DEBUG " << day << "." << month << "." << year << endl; }

};

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.day << '.' << dt.month << '.' << dt.year << ' ';
    return os;
}

int Date::operator <(Date d1)
{
    return  (year < d1.year)  ||
            (year == d1.year && month < d1.month) ||
            (year == d1.year && month == d1.month && day < d1.day);
}



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


bool compare(pair<Date, string>&i, pair<Date, string>&j)
{
    return i.first < j.first;
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
    string str;

    while (fin) {
            getline(fin, str);
            svec.push_back(str); /* чтение всего содержимого из файла */
            str.clear();
        }
/*
* запись нужных частей в другой файл: "SuperBackup_"
*/
    auto it = svec.begin();
    for (; it != svec.end(); ++it) {
            auto pos1 = it->find("body=") + 15;
            auto pos2 = it->find("р\"");
            if (pos1 != string::npos && pos2 != string::npos) {
                while (pos1 != pos2) {
                      fout << it->at(pos1); // fout
                      ++pos1;
                    }
                fout << "\n";
                }
        }
    svec.clear();
    fin.close();
    fout.close();


    fin.open("SuperBackup_", ios::in); /* для чтения всего содержимого из файла */

    while (fin) {
            getline(fin, str);
            svec.push_back(str);
            str.clear();
        }

    vector<Date>    dvec; /*--- all dates from file---*/
    vector<string>  strvec;
    vector<pair<Date, string>> coll, coll1;   /*---coll1 for DEBUGING ---*/


    svec.pop_back(); /* надо удалить пустую строку */
    it = svec.begin();
    /* в этом цикле разбиваем прочитанные из файла строки на "дату" и "баланс" */
    for (; it != svec.end(); ++it) {
            size_t i = 0;
            while (i < 8) {
                    str += it->at(i);
                    ++i;
                    }
            dvec.push_back(str);
            str.clear();
            auto p1 = it->find("Баланс:");
            if(p1 != string::npos)
                while (p1 < it->size()) {
                        str += it->at(p1);
                        ++p1;
                    }
            strvec.push_back(str);
            str.clear();
        }

    fin.close();

    auto dvec_it   = dvec.begin();
    auto strvec_it = strvec.begin();

    for (; dvec_it != dvec.end(); ++dvec_it, ++strvec_it)
        coll.push_back(make_pair(*dvec_it, *strvec_it));

    coll1 = coll;

    sort(coll.begin(), coll.end(), compare);

    auto iterator = coll.begin();
    auto iterator1 = coll1.begin();
    for(; iterator != coll.end(); ++iterator, ++iterator1){
        cout << iterator->first << " " << iterator->second << " -- "; /* отсортировано*/
        cout << iterator1->first << " " << iterator1->second << endl; /* не отсортировано*/
        }




//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}


