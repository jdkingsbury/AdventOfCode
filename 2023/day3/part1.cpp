#include <cctype>
#include <ios>
#include <iostream>
#include <fstream>
#include <ostream>
#include <set>
#include <vector>
#include <string>

int getNumber(std::vector<std::vector<char> > &board, int row, int col) {
  std::string num;

  while (std::isdigit(board[row][col])) {
    if (col==0 || !std::isdigit(board[row][col-1])) {
      break; 
    }
    col--;
  }

  while (true) {
    if (!std::isdigit(board[row][col]) || col >= board[row].size()) {
      break;
    }
    num.push_back(board[row][col]); 
    col++; 
  }

  return std::stoi(num);
}


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

  std::vector<std::vector<char> > board;
  std::vector<int> part_numbers;

  std::string line;

  while (std::getline(f, line)) {
    std::vector<char> row;

    for (int i=0; i<line.length(); i++) {
      row.push_back(line[i]);
    }
    board.push_back(row);
  }

  for (int i=0; i<board.size(); i++) {
    for (int j=0; j<board[0].size(); j++) {
      if (!std::isdigit(board[i][j]) && board[i][j]!='.') {

        int temp = 0;
        std::set<int> partnum;

        if (std::isdigit(board[i-1][j-1])) {
          temp = getNumber(board, i-1, j-1); 
          partnum.insert(temp);
        }
        if (std::isdigit(board[i-1][j])) {
          temp = getNumber(board, i-1, j) ;
          partnum.insert(temp);
        }
        if (std::isdigit(board[i-1][j+1])) {
          temp = getNumber(board, i-1, j+1);
          partnum.insert(temp);
        }
        if (std::isdigit(board[i+1][j-1])) {
          temp = getNumber(board, i+1, j-1);
          partnum.insert(temp);
        }
        if (std::isdigit(board[i+1][j])) {
          temp = getNumber(board, i+1, j);
          partnum.insert(temp);
        } 
        if (std::isdigit(board[i+1][j+1])) {
          temp = getNumber(board, i+1, j+1);
          partnum.insert(temp);
        } 
        if (std::isdigit(board[i][j+1])) {
          temp = getNumber(board, i, j+1);
          partnum.insert(temp);
        }
        if (std::isdigit(board[i][j-1])) {
          temp = getNumber(board, i, j-1);
          partnum.insert(temp);
        }

        for (auto it = partnum.begin(); it != partnum.end(); it++) {
          part_numbers.push_back(*it);
        }

      } 
    } 
  }

  int total = 0;

  for (int i=0; i<part_numbers.size(); i++) {
    total += part_numbers[i];
  }

  std::cout << total << std::endl;
  return 0;
}
