#include <algorithm>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "No file to open" << std::endl;
    return 0;
  }

  std::string file = argv[1];
  std::string line;
  std::vector<int> blocks_needed;

  int redblocks = 12;
  int greenblocks = 13;
  int blueblocks = 14;

  std::ifstream f(file, std::ios::in);

  if (!f) {
    std::cout << "File is unavailable" << std::endl;
    return 0;
  }
  
  while (std::getline(f, line)) {

    for (int i = 0; i < line.length(); i++) {
      if (line[i]==':') {
        line[i] = ' ';
      } else if (line[i]==',') {
        line[i] = ' ';
      } else if (line[i]==';') {
        line[i] = ' ';
      }
    }

    if (line.substr(0, 4) == "Game") {
      std::istringstream s(line.substr(4));
      std::string group;
      bool possible = true;
      
      int redblocksfound = 0;
      int greenblocksfound = 0;
      int blueblocksfound = 0;

      int gameId = 0;

      s >> gameId;
      
      std::string color;
      int number = 0;
      
      while (s >> number >> color) {
        if (color == "green") {
          if (greenblocksfound < number) {
            greenblocksfound = number; 
          }
        } else if (color == "blue") {
          if (blueblocksfound < number) {
            blueblocksfound = number;
          }
        } else if (color == "red") {
          if (redblocksfound < number) {
            redblocksfound = number;
          }
        }
      }

      int minimum = greenblocksfound * blueblocksfound * redblocksfound;
      blocks_needed.push_back(minimum);
    }
  }

  int total = 0;

  for (int i=0; i < blocks_needed.size(); i++) {
    total += blocks_needed[i];
  }

  std::cout << total << std::endl;

  return 0;
}
