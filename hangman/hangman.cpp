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
  int triesLeft = 5;
  char letter;
  std::map<char, bool> userTries;

  std::cout << "Welcome to the hangman game!\n";

  while (!userWin && !gameOver) {
    std::cout << "Digite uma letra: ";
    std::cin >> letter;

    if (userTries[letter]) {
      std::cout << "Você ja digitou essa letra! Tente outra\n";
      continue;
    }

    userTries[letter] = true;

    if (letterExist(letter)) {
      std::cout << "Você acertou! Continue\n";
    } else {
      std::cout << "Você errou! Tente novamente\n";
    }

    for (char letter : SECRET_WORD) {
      if (userTries[letter]) {
        std::cout << letter << " ";
      } else {
        std::cout << "_ ";
      }
    }

    std::cout << "\n";

    --triesLeft;
   }
}
