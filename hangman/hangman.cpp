#include <iostream>
#include <string>

const std::string SECRET_WORD = "teste de string";
bool userWin = false;
bool gameOver = false;

int main() {

  char word;

  while (!userWin && !gameOver) {
    std::cout << "Digite uma letra: ";
    std::cin >> word;
    std::cout << word << "\n";
  }
}
