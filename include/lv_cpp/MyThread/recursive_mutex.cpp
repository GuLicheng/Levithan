#include "mutex.hpp"
#include "lock.hpp"

#include <iostream>
#include <string>
#include <thread>

class X {
    RecursiveTimedMutex m;
    std::string shared;
  public:
    void fun1() {
      LockGuard lk(m);
      shared = "fun1";
      std::cout << "in fun1, shared variable is now " << shared << '\n';
    }
    void fun2() {
      LockGuard lk(m);
      shared = "fun2";
      std::cout << "in fun2, shared variable is now " << shared << '\n';
      fun1(); // recursive lock becomes useful here
      std::cout << "back in fun2, shared variable is " << shared << '\n';
    };
};
 
int main() 
{
    X x;
    std::thread t1(&X::fun1, &x);
    std::thread t2(&X::fun2, &x);
    t1.join();
    t2.join();
}