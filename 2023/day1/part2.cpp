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

  std::string numwords[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

  std::vector<int> all_numbers;

  while (std::getline(f, line)) {

    std::deque<int> numbers;
    std::string number;

    for (int i=0; i<line.size(); i++) {
      if (std::isdigit(line[i])) {
        numbers.push_back(line[i] - '0');
      } else if (line.substr(i, 3) == numwords[0]) {
        numbers.push_back(1);
      } else if (line.substr(i, 3) == numwords[1]) {
        numbers.push_back(2);
      } else if (line.substr(i, 5) == numwords[2]) {
        numbers.push_back(3);
      } else if (line.substr(i, 4) == numwords[3]) {
        numbers.push_back(4);
      } else if (line.substr(i, 4) == numwords[4]) {
        numbers.push_back(5);
      } else if (line.substr(i, 3) == numwords[5]) {
        numbers.push_back(6);
      } else if (line.substr(i, 5) == numwords[6]) {
        numbers.push_back(7);
      } else if (line.substr(i, 5) == numwords[7]) {
        numbers.push_back(8);
      } else if (line.substr(i, 4) == numwords[8]) {
        numbers.push_back(9);
      }
    }

    if (!numbers.empty()) {
      number.push_back('0' + numbers.front());
      number.push_back('0' + numbers.back());

      all_numbers.push_back(std::stoi(number));
    }
  }

  f.close();

  int total = 0;

  for (int i=0; i<all_numbers.size(); i++) {
    total += all_numbers[i];
  }

  std::cout << total << std::endl;

  return 0;
}
