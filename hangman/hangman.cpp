#include <iostream>
#include <string>
#include <map>

const std::string SECRET_WORD = "MELANCIA";
bool userWin = false;

bool letterExist(char letter) {
  for (char secretWordLetter : SECRET_WORD) {
    if (letter == secretWordLetter) {
      return true;
    }
  }
  return false;
}

auto gameIsOver(std::map<char, bool> userTries) {
  int lettersRemaining = SECRET_WORD.size();

  for (char letter : SECRET_WORD) {
    if (userTries[letter]) {
      --lettersRemaining;
    }
  }

  struct returnStruct {
    int lettersRemaining;
    bool gameOver;
  };

  if (lettersRemaining) {
    return returnStruct{ lettersRemaining, false };
  } else {
    return returnStruct{ lettersRemaining, true };
  }
}

int handleDifficulty(int difficulty) {
  switch (difficulty) {
        case 1:
            return 3;
            break;

        case 2:
            return 5;
            break;

        case 3:
            return 8;
            break;

        case 4:
            return 12;
            break;

        case 5:
            return 15;
            break;
        default:
            throw std::invalid_argument("Insert a integer between 1 and 5 to select difficulty.");
            break;
    }
}

int main() {
  int errorsLeft = 5;
  int difficulty;
  std::string wrongAttemps;
  char letter;
  std::map<char, bool> userTries;

  std::cout << "****************************\n";
  std::cout << "Welcome to the hangman game!" << std::endl;
  std::cout << "****************************\n\n";
  std::cout << "First of all, select your dificulty:" << std::endl;
  std::cout << "1. Extreme (3 attemps);" << std::endl;
  std::cout << "2. Hard (5 attemps);" << std::endl;
  std::cout << "3. Medium (8 attemps);" << std::endl;
  std::cout << "4. Easy (12 attemps);" << std::endl;
  std::cout << "5. Very Easy (15 attemps)\n\n";
  
  std::cout << "Option: ";
  std::cin >> difficulty;
  std::cout << "\n\n";

  errorsLeft = handleDifficulty(difficulty);

  while (!userWin && errorsLeft != 0) {
    std::cout << "Digite uma letra: ";
    std::cin >> letter;

    if (userTries[letter]) {
      std::cout << "Você ja digitou essa letra! Tente outra\n";
      continue;
    }

    userTries[letter] = true;

    if (letterExist(letter)) {
      auto [lettersRemaining, gameOver] = gameIsOver(userTries);
      if (gameOver) {
        std::cout << "Parabéns, você ganhou!!! A palavra era \"" << SECRET_WORD << "\"\n";
        return 0;
      } else {
        std::cout << "Você acertou. Continue assim!\n";
        if (lettersRemaining == 1) {
          std::cout << "Ainda falta " << lettersRemaining << " letra.\n";  
        } else {
          std::cout << "Ainda faltam " << lettersRemaining << " letras.\n";
        }
      }
    } else {
      --errorsLeft;
      if (wrongAttemps.size()) {
        wrongAttemps = wrongAttemps + "-" + letter;
      } else {
        wrongAttemps = letter;
      }
      std::cout << "Você errou! Tente novamente (tentativas restantes: " << errorsLeft << ").\n";
      std::cout << "Erros: " << wrongAttemps << ".\n";
    }

    for (char letter : SECRET_WORD) {
      if (userTries[letter]) {
        std::cout << letter << " ";
      } else {
        std::cout << "_ ";
      }
    }

    std::cout << "\n\n";

    if (!errorsLeft && !userWin) {
      std::cout << "Game over. the word was \"" << SECRET_WORD << "\"" << std::endl;
    } else if (userWin) {
      std::cout << "Congratulation, you win. The word was \"" << SECRET_WORD << "\"" << std::endl;
    }
  }
}
