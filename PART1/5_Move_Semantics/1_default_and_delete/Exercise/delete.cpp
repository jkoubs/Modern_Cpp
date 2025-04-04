struct OnlyInt {
  OnlyInt(int) {}

  template <typename T> OnlyInt(T) = delete;
};

int main() {

  OnlyInt(5);
  OnlyInt(5L);
  OnlyInt(5LL);
  OnlyInt(5UL);
  OnlyInt(5.5);
  OnlyInt('5');
  OnlyInt(true); // integral promotion -> 1
}

/*
GOAL: Define a class template, that can be invoked with an int value
*/