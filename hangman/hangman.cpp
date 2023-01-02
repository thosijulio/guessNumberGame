#include <iostream>
#include <string>

const std::string SECRET_WORD = "teste de string";
bool userWin = false;
bool gameOver = false;

bool letterExist(char letter) {
  for (char secretWordLetter : SECRET_WORD) {
    if (letter == secretWordLetter) {
      return true;
    }
  }
  return false;
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
