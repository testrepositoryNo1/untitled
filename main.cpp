#include "main.h"

using namespace std;

template <class T>
void print(const T &v)
{
    for (auto a: v)
      cout << a << endl;
}

int main ()
{
        setlocale(0, "");
        srand(time(0));
        srand(rand());
        ostream_iterator<int> out(cout, "\n");
        boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        string s;
        cout << "password: ";
        getline(cin, s);

        cout << s << endl;

//---------------------------------------------------------------
        boost::chrono::milliseconds end(clock());
        using ms = boost::chrono::milliseconds;
        ms dur = boost::chrono::duration_cast<ms>(end - start);
        double dd = dur.count();
        cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}






