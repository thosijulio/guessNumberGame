#include <iostream>
#include <string>
#include <map>

const std::string SECRET_WORD = "MELANCIA";
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
  bool triesLeft = 5;
  char letter;
  std::map<char, bool> userTries;

  std::cout << "Welcome to the hangman game!\n";

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
