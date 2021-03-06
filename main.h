#ifndef MAIN_H
#define MAIN_H
#include "stdfx.h"

void Srand()
{
    srand(time(0));
    srand(rand());
}

class my_boost_int_Rnd
{

public:
  int64_t int_boost_rnd()
  {
    boost::random::mt19937 temp_gen(clock() * time(0) / rand());       /* seed */
    boost::random::uniform_int_distribution<>temp_di;
    boost::random::mt19937 gen(temp_di(temp_gen));
    boost::random::uniform_int_distribution<> dist;
    return dist(gen);
  }


  int64_t int_boost_rnd(int a, int b)
  {
    boost::random::mt19937 temp_gen(clock() * time(0) / rand());       /* seed is clock*/
    boost::random::uniform_int_distribution<>temp_di;
    boost::random::mt19937 gen(temp_di(temp_gen));
    boost::random::uniform_int_distribution<> dist(a, b);
    return dist(gen);
  }

  long double double_boost_rnd()
  {
    my_boost_int_Rnd ob;
    double r =  ob.int_boost_rnd() / 1.0;
    double x = r / ob.int_boost_rnd() * ob.int_boost_rnd(1, 100);
    return x;
  }

  long double double_boost_rnd(double a, double b)
  {
      my_boost_int_Rnd ob;
      boost::random::mt19937 temp_gen(clock() * time(0) / rand());       /* seed is clock*/
      boost::random::uniform_real_distribution<>temp_di;
      boost::random::mt19937 gen(temp_di(temp_gen));
      boost::random::uniform_real_distribution<> dist(a, b);
      long double r = dist(gen) * ob.double_boost_rnd();

      bool _break = false;

      while (!_break) {
              if (r <= b && r >= a) {
                      _break = true;
                  }
              else {
                      r = dist(gen) * ob.double_boost_rnd();
                  }
          }
      return r;
  }
};


void gen(std::vector<int> &v, size_t _size)
{
    my_boost_int_Rnd rnd;
    for (size_t i = 0; i < _size; ++i) {
        v.push_back(rnd.int_boost_rnd(0, 100));
        }
}

void gen(std::vector<int> &v, size_t _size, int dest_from, int dest_to)
{
    my_boost_int_Rnd rnd;
    for (size_t i = 0; i < _size; ++i) {
        v.push_back(rnd.int_boost_rnd(dest_from, dest_to));
        }
}

#endif // MAIN_H
