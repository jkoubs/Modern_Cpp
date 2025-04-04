// movePerformance.cpp

#include <array>
#include <chrono>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int SIZE = 10000000;

template <typename T> void measurePerformance(T &t, const std::string &cont) {

  std::cout << std::fixed << std::setprecision(10);

  auto begin = std::chrono::system_clock::now();
  T t1(t);
  auto last = std::chrono::system_clock::now() - begin;
  std::cout << cont << std::endl;
  auto copyTime = std::chrono::duration<double>(last).count();
  std::cout << "    Copy: " << copyTime << " sec" << std::endl;

  begin = std::chrono::system_clock::now();
  T t2(std::move(t));
  last = std::chrono::system_clock::now() - begin;
  auto moveTime = std::chrono::duration<double>(last).count();
  std::cout << "    Move: " << moveTime << " sec" << std::endl;

  std::cout << std::setprecision(2);
  std::cout << "    Ratio (copy time/move time): " << (copyTime / moveTime)
            << std::endl;

  std::cout << std::endl;
}

int main() {

  std::cout << std::endl;

  {
    std::array<int, SIZE / 1000> myArray;
    measurePerformance(myArray, "std::array<int,SIZE/1000>");
  }

  {
    std::vector<int> myVec(SIZE);
    measurePerformance(myVec, "std::vector<int>(SIZE)");
  }

  {
    std::deque<int> myDec(SIZE);
    measurePerformance(myDec, "std::deque<int>(SIZE)");
  }

  {
    std::list<int> myList(SIZE);
    measurePerformance(myList, "std::list<int>(SIZE)");
  }

  {
    std::forward_list<int> myForwardList(SIZE);
    measurePerformance(myForwardList, "std::forward_list<int>(SIZE)");
  }

  {
    std::string myString(SIZE, ' ');
    measurePerformance(myString, "std::string(SIZE,' ')");
  }

  std::vector<int> tmpVec(SIZE);
  std::iota(tmpVec.begin(), tmpVec.end(), 0);

  {
    std::set<int> mySet(tmpVec.begin(), tmpVec.end());
    measurePerformance(mySet, "std::set<int>");
  }

  {
    std::unordered_set<int> myUnorderedSet(tmpVec.begin(), tmpVec.end());
    measurePerformance(myUnorderedSet, "std::unordered_set<int>");
  }

  {
    std::map<int, int> myMap;
    for (auto i = 0; i <= SIZE; ++i)
      myMap[i] = i;
    measurePerformance(myMap, "std::map<int,int>");
  }

  {
    std::unordered_map<int, int> myUnorderedMap;
    for (auto i = 0; i <= SIZE; ++i)
      myUnorderedMap[i] = i;
    measurePerformance(myUnorderedMap, "std::unordered_map<int,int>");
  }
}

/*

* GOAL:
Compare the performance of copy vs move operations for various C++ STL
containers.

By measuring the time it takes to copy/move containers such as :
    *vectors
    *lists
    *sets
    *map
    *strings

* Results:
Move semantics is faster and more efficient than copying.
std::move can significantly improve performance in real-world applications
involving large data structures.


NOTE 1:
Curly braces (inside the main) are there to isolate each test and manage
memory better. They create separate scopes for each container being tested.
We create each container with its scope so that it will be automatically
released. Because the containers are quite big, releasing their memory is a
must.

NOTE 2:
std::array<int, SIZE> stores all its elements on the stack, not the heap.
The stack has limited memory (usually a few megabytes).
Trying to allocate 10 million ints (which is ~40 MB) on the stack will likely
cause a stack overflow, crashing the program. Thats why we reduce its size.
*/