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
  std::vector<int> gameIds;

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
      std::cout << "Game: " << gameId << " ";
      
      std::string color;
      int number = 0;
      
      while (s >> number >> color) {
        std::cout << number << " ";
        std::cout << color << " ";
        if (color == "green") {
          greenblocksfound = number; 
        } else if (color == "blue") {
          blueblocksfound = number;
        } else if (color == "red") {
          redblocksfound = number;
        }

        if (greenblocksfound > greenblocks || blueblocksfound > blueblocks || redblocksfound > redblocks) {
          possible = false;      
          break;
        }
      }
      std::cout << std::endl;

      if (possible) {
        gameIds.push_back(gameId);
      }
    }
  }

  int total = 0;

  for (int i=0; i<gameIds.size(); i++) {
    total += gameIds[i];
  }

  std::cout << total << std::endl;

  return 0;
}
