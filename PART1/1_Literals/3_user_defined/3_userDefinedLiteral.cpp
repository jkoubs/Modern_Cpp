#include <iostream>
using namespace std;

constexpr long double operator"" _km(long double distance) {
  return distance * 1000.0; // Convert kilometers to meters
}

int main() {
  long double distance = 3.5_km; // 3.5 kilometers in meters
  cout << "Distance in meters: " << distance << "m" << endl;
  return 0;
}
