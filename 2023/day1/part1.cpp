#include <cctype>
#include <deque>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


int main (int argc, char *argv[]) {

  if (argc < 2) {
    std::cout << "No file to open" << std::endl; 
    return 0;
  }

  std::string file = argv[1];
  std::string line;

  std::ifstream f(file, std::ios::in);

  if (!f) {
    std::cout << "File is unavailable" << std::endl;
  }

  std::vector<int> all_numbers;
  int count = 0;

  while (std::getline(f, line)) {

    std::deque<int> numbers;
    std::string number;

    for (int i=0; i<line.size(); i++) {
      if (std::isdigit(line[i])) {
        numbers.push_back((int)line[i]);
      } 
    }

    if (!numbers.empty()) {
      number.push_back(numbers.front());
      number.push_back(numbers.back());

      all_numbers.push_back(std::stoi(number));
    }
  }

  int total = 0;

  for (int i=0; i<all_numbers.size(); i++) {
    total += all_numbers[i];
  }

  std::cout << total << std::endl;

  return 0;
}
