#include "main.h"

using namespace std;

template <class T>
void print(const T &v)
{
    for (auto a: v)
      cout << a << endl;
}



template <typename T>
class Stack {
private:
    vector<T> elems; // Элементы
public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const { return elems.empty(); }
};

template <typename T>
void Stack<T>::push(T const& elem)
{
    elems.push_back(elem) ; // Добавление в стек
                            // копии передаваемого
                            // элемента
}

template <typename T>
void Stack<T>::pop()
{
    if (elems.empty()) {
        throw out_of_range(" Stack< >: : pop () : "" empty stack");
      }
    elems.pop_back() ; // Удаление последнего элемента
}

template <typename T>
T Stack<T>::top() const
{
    if (elems.empty()) {
        throw out_of_range(" Stack< >: : top () :"" empty stack");
      }
    return elems.back(); // Возврат копии последнего элемента
}

template <typename T>
class Test
{
  T var;
public:
  Test(T _var) { var = _var; }
  void show() { cout << var << endl; }
};

int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    Test<int> tst1(987);
    tst1.show();

    Test<string> tst2("string");
    tst2.show();



//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}
