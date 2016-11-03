#include "main.h"

using namespace std;

template <class T>
void print(const T &v)
{
    for (auto a: v)
      cout << a << " ";
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
  Test() { }
  Test(T _var) { var = _var; }
  void show() { cout << var << endl; }
  void func(T args);
};
template <typename T>
void Test<T>::func(T args)
{
  cout << boost::typeindex::type_id_runtime(args).pretty_name() << endl;
}


int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    my_boost_int_Rnd rnd;
    vector<int> vec1;
    vector<int> vec2;
    vector<int> m_vec(20);

    for (size_t i = 0; i < 10; ++i) {
        vec1.push_back(rnd.int_boost_rnd(1,20));
        vec2.push_back(rnd.int_boost_rnd(1, 20));
      }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(),vec2.end());

    print(vec1);
    cout << endl;
    print(vec2);
    cout << endl;

    merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), m_vec.begin());

    print(m_vec);
    cout << endl;



    //find(vec.begin(), vec.end(), 987);
    //auto a = binary_search(vec.begin(),vec.end(), 987);

    //cout << boost::typeindex::type_id_runtime(a).pretty_name() << endl;

//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count();
    cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}
