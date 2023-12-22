#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>

int main (int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Failed to open file" << std::endl;
    return 0;
  }
 
  std::ifstream f(argv[1]);

  if (!f) {
    std::cout << "File is unavailable" << std::endl;
    return 0;
  }

  std::map<int, int> cards;
  std::string line;

  while (std::getline(f, line)) {
    std::stringstream s(line);
    std::string winning_string;
    std::set<int> winning_numbers;

    std::string temp;
    int card = 0;

    s >> temp >> card >> temp;
    cards[card]++;

    std::getline(s, winning_string, '|');
    std::stringstream winning(winning_string);

    int num;
    while (winning >> num) {
      winning_numbers.insert(num);
    }

    int matches = 0;
    while (s >> temp) {
      matches += winning_numbers.count(std::stoi(temp));
    }
    std::cout << matches << std::endl;

    for (int i=1; i<=matches; i++) {
      cards[card+i] += cards[card];
    }
      
  }

  int total = 0;
  for (auto it = cards.begin(); it != cards.end(); it++) {
    std::cout << it->first << " " << it->second << std::endl;
    total += it->second;
  }

  std::cout << total << std::endl;
  
  return 0;
}
