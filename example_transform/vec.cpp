#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> map_all(std::vector<std::string> strings) {
  std::vector<std::string> outputs;

  std::transform(strings.begin(), strings.end(), std::back_inserter(outputs), [](std::string s) {
    return s;
  });

  return outputs;
}

using PairTuples = std::vector<std::tuple<std::string, std::string>>;
using Pairs = std::vector<std::pair<std::string, std::string>>;

Pairs tuple_map_all(PairTuples items) {
  std::vector<std::pair<std::string, std::string>> outputs;

  std::transform(items.begin(), items.end(), std::back_inserter(outputs), [](std::tuple<std::string, std::string> s) {
    return std::make_pair(std::get<0>(s), std::get<1>(s));
  });

  return outputs;
}

int main() {
  std::vector<std::string> outputs;
  std::vector<std::string> inputs = { "a", "b", "c", "d", "e" };

  outputs = map_all(inputs);

  for (std::string x : outputs) {
    std::cout << x << std::endl;
  }


  PairTuples inputs_tuple = { std::make_tuple("a", "a"), std::make_tuple("b", "b") };
  Pairs outputs_pairs = tuple_map_all(inputs_tuple);

  for (std::pair<std::string, std::string> x : outputs_pairs) {
    std::cout << x.first << std::endl;
    std::cout << x.second << std::endl;
  }

  return 0;
}
