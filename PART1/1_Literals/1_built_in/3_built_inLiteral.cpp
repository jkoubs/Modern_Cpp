#include <chrono>
#include <iostream>

using namespace std::literals::chrono_literals;

int main() {

  std::cout << '\n';

  auto schoolHour = 45min;

  auto shortBreak = 300s;
  auto longBreak = 0.25h;

  auto schoolWay = 15min;
  auto homework = 2h;

  auto schoolDayInSeconds =
      2 * schoolWay + 6 * schoolHour + 4 * shortBreak + longBreak + homework;

  std::cout << "School day in seconds: " << schoolDayInSeconds.count() << '\n';
}