#include <iostream>
#include <list>
#include <string>

struct myChannel {
  std::string Name;
  int Followers;

  myChannel(std::string name, int followers) {
    Name = name;
    Followers = followers;
  }
};

std::ostream &operator<<(std::ostream &COUT, myChannel &mychannel) {
  COUT << "Channel Name: " << mychannel.Name << std::endl;
  COUT << "Followers: " << mychannel.Followers << std::endl;
  return COUT;
}

struct MyCollection {
  std::list<myChannel> myChannels;

  void operator+=(myChannel &mychannel) {
    this->myChannels.push_back(mychannel);
  }
};

std::ostream &operator<<(std::ostream &COUT, MyCollection &mycollection) {
  for (myChannel jkchannel : mycollection.myChannels) {
    COUT << jkchannel;
  }
  return COUT;
}
int main() {
  myChannel ch = myChannel("Jason Cpp I", 255);
  myChannel ch2 = myChannel("Jason Cpp II", 51);
  myChannel ch3 = myChannel("Jason Cpp III", 31);
  myChannel ch4 = myChannel("Jason Cpp IV", 12);
  std::cout << ch << ch2;

  // operator<<(std::cout, ch3); same way to overload

  MyCollection my_collection;
  my_collection += ch3;
  my_collection += ch4;
  std::cout << my_collection;
}