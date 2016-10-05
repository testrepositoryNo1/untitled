#ifndef MAIN_H
#define MAIN_H
#include "stdfx.h"

class my_boost_int_Rnd
{
public:

  int boost_rnd()
  {
    boost::random::mt19937 temp_gen(clock());       /* seed is clock*/
    boost::random::uniform_int_distribution<>temp_di;
    boost::random::mt19937 gen(temp_di(temp_gen));
    boost::random::uniform_int_distribution<> dist;
    return dist(gen);
  }


  int boost_rnd(int a, int b)
  {
    boost::random::mt19937 temp_gen(clock());       /* seed is clock*/
    boost::random::uniform_int_distribution<>temp_di;
    boost::random::mt19937 gen(temp_di(temp_gen));
    boost::random::uniform_int_distribution<> dist(a, b);
    return dist(gen);
  }

};



#endif // MAIN_H
