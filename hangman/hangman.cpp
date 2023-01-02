#include <iostream>
#include <string>

const std::string SECRET_WORD = "teste de string";
bool userWin = false;
bool gameOver = false;

bool letterExist(char letter) {
  for (int index = 0; index < SECRET_WORD.size(); ++ index) {
    if (letter == SECRET_WORD[index]) {
      return true;
    } else return false;
  }
}

int main() {

  char letter;

  while (!userWin && !gameOver) {
    std::cout << "Digite uma letra: ";
    std::cin >> letter;

    if (letterExist(letter)) {
      std::cout << "Você acertou! Continue\n";
    } else {
      std::cout << "Você errou! Tente novamente\n";
    }
    std::cout << letter << "\n";
  }
}
