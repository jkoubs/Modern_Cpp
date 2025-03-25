struct MyDouble {

  double myVal;
  constexpr MyDouble(double v) : myVal(v) {}
  constexpr double getVal() { return myVal; }
};

int main() { MyDouble myDoub(5.5); }

/**
 Use Compiler Explorer to visualize that this code is evaluated at compile time
because there is not colors at the upper section:


 struct MyDouble {

    double myVal;
    constexpr MyDouble(double v): myVal(v){}
    constexpr double getVal(){return myVal;}
};

*/