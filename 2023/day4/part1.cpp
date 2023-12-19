#include <algorithm>
#include <ios>
#include <iostream>
#include <fstream> 
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
  
  if (argc < 2) {
    std::cout << "Failed to open file" << std::endl;
    return 0;
  }

  std::ifstream f(argv[1], std::ios::in);

  if (!f) {
    std::cout << "File is unavailable" << std::endl;
    return 0; 
  }

  std::string line;
  std::vector<int> cards;

  while (std::getline(f, line)) {
    std::set<int> winning_numbers;
    std::vector<int> winners_found;
    
    for (int i=0; i < line.length(); i++) {
      if (line[i] == ':') {
        line[i] = ' ';
      } 
    }

    if (line.substr(0, 4) == "Card") {
      std::istringstream s(line.substr(4)); 
      bool checking_cards = false;
      int card_num = 0;
      std::string temp;

      s >> card_num; 

      while (s >> temp) {
        if (temp == "|") {
          checking_cards = true;
        } else if (checking_cards) {
          if (winning_numbers.count(std::stoi(temp))) {
            winners_found.push_back(std::stoi(temp));
          }
        } else {
          winning_numbers.insert(std::stoi(temp));  
        }
      }

      int total = 0;

      for (int i=0; i<winners_found.size(); i++) {
        if (i==0) {
          total += 1; 
        } else {
          total *= 2;
        } 
      }
      cards.push_back(total);
    }
  }

  int total = 0;

  for (int i=0; i<cards.size(); i++) {
    total += cards[i];
  }

  std::cout << total << std::endl;

  return 0;
}
