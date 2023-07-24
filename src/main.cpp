#include "../include/lexer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// TODO: Write Unit Test
// TODO: Parser
// TODO: Comments
// TODO: UML Class diagram
// TODO: Flowchart
// TODO: Documentation

int main(int argc, char const *argv[]) {
  std::ifstream inFile(argv[1]);
  if (!inFile) {
    std::cerr << "Error opening input file" << std::endl;
    return 1;
  }

  std::stringstream buffer;
  buffer << inFile.rdbuf();

  std::string text = buffer.str();

  Lexer test(text);

  std::string result = test.result();

  if (argc == 3) {
    std::fstream outFile;
    outFile.open(argv[2], std::ios::out);
    if (!outFile.is_open()) {
      std::cerr << "Error opening input file" << std::endl;
      return 1;
    }

    outFile << result << std::endl;
    outFile.close();
  } else {
    std::cout << result;
  }

  inFile.close();

  return 0;
}
