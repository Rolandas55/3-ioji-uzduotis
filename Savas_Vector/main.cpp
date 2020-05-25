#include <iostream>
#include "Vector.h"
#include <vector>
#include <ctime>
#include <cstdio>

int main() {
  //Vector<int>a(10,2);
  //Vector<int>b(a);
  //std::cout <<"a didis (inicijavimas): "<<a.size()<<std::endl;
  // std::cout <<"a viso (inicijavimas): "<<a.capacity()<<std::endl;
  //a.push_back(25);

  std::clock_t start=0;
  double duration=0;
    unsigned int sz = 10000;
    Vector<int> v1;
    for (int i = 1; i <= sz; ++i)
    v1.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "Vector 10000 laikas: " << duration << std::endl;
  v1.uncreate();

  start=0;
  duration=0;
  sz = 10000;
    std::vector<int> v2;
    for (int i = 1; i <= sz; ++i)
    v2.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "std::vector 10000 laikas: " << duration << std::endl;
  v2.clear();

  start=0;                          //2
  duration=0;
  sz = 100000;
    for (int i = 1; i <= sz; ++i)
    v1.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "Vector 100000 laikas: " << duration << std::endl;
  v1.uncreate();

  start=0;
  duration=0;
  sz = 100000;
    for (int i = 1; i <= sz; ++i)
    v2.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "std::vector 100000 laikas: " << duration << std::endl;
  v2.clear();

    start=0;                          //3
  duration=0;
  sz = 1000000;
    for (int i = 1; i <= sz; ++i)
    v1.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "Vector 1000000 laikas: " << duration << std::endl;
  v1.uncreate();

  start=0;
  duration=0;
  sz = 1000000;
    for (int i = 1; i <= sz; ++i)
    v2.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "std::vector 1000000 laikas: " << duration << std::endl;
  v2.clear();

  start=0;                          //4
  duration=0;
  sz = 10000000;
    for (int i = 1; i <= sz; ++i)
    v1.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "Vector 10000000 laikas: " << duration << std::endl;
  v1.uncreate();

  start=0;
  duration=0;
  sz = 10000000;
    for (int i = 1; i <= sz; ++i)
    v2.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "std::vector 10000000 laikas: " << duration << std::endl;
  v2.clear();

  start=0;                          //5
  duration=0;
  sz = 100000000;
    for (int i = 1; i <= sz; ++i)
    v1.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "Vector 100000000 laikas: " << duration << std::endl;
  v1.uncreate();

  start=0;
  duration=0;
  sz = 100000000;
    for (int i = 1; i <= sz; ++i)
    v2.push_back(i);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout << "std::vector 100000000 laikas: " << duration << std::endl;
  v2.clear();


  /*a[9]=125;
  b[9]=89;
  std::cout << "a didis (po reserv): " << a.size()<<std::endl;
  for (int i=0;i<a.size();i++)
    std::cout << i << "\t"<< a[i] <<std::endl;*/
  //a.~Vector();
  /*std::cout << "a didis (po destruktoriaus): " <<a.size()<<std::endl;
  std::cout << "a viso (po destruktoriaus): " <<a.capacity()<<std::endl;
  for (int i=0;i<b.size();i++)
    std::cout << i << "\t" << b.at(i) <<std::endl;*/
  //b.~Vector();
}
