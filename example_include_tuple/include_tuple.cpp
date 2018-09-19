#include <vector>
#include <tuple>
#include <iostream>

class xtuple : public std::tuple<int, int> {
  public:
    xtuple(int x_val, int y_val);
    int id();
    int score();
};

xtuple::xtuple(int x_val, int y_val) : tuple(x_val, y_val) {
}

int xtuple::id() {
  return std::get<0>(*this);
}
int xtuple::score() {
  return std::get<1>(*this);
}

class tmpl {
  private:
    int x, y;
  public:
    tmpl(int x_val, int y_val);
    const int& x_p() const;
    const int& y_p() const;
};

tmpl::tmpl(int x_val, int y_val) {
  x = x_val;
  y = y_val;
}

const int& tmpl::x_p() const {
  return x;
}
const int& tmpl::y_p() const {
  return y;
}

class input {
  private:
    std::tuple<int, int> point;
  public:
    input(int x, int y);
    int x();
    int y();
};

input::input(int x_val, int y_val) {
  point = std::make_tuple(x_val, y_val);
}

int input::x() {
  return std::get<0>(point);
}

int input::y() {
  return std::get<1>(point);
}

void print_extends_tuple(std::tuple<int, int> a) {
  std::cout << "0: " << std::get<0>(a) << "\n";
  std::cout << "1: " << std::get<1>(a) << "\n";
}



int main() {
  input i1 =* new input(1, 2);
  input i2 =* new input(5, 2);
  input i3 =* new input(3, 6);

  std::cout << i1.x() << std::endl;
  std::cout << i2.x() << std::endl;
  std::cout << i3.x() << std::endl;

  xtuple v1 =* new xtuple(1, 2);
  print_extends_tuple(v1);

  xtuple v2 =* new xtuple(6, 9);
  print_extends_tuple(v2);

  std::cout << v2.id() << std::endl;
  std::cout << v2.score() << std::endl;

  tmpl t1 =* new tmpl(9, 6);

  std::cout << t1.x_p() << std::endl;
  std::cout << t1.y_p() << std::endl;
}
