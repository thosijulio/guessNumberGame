/*
    Padrao para adição de bibliotecas em C++: 
        "#include" e o nome da biblioteca que será utilizada entre "<>"
*/
// iostream é uma biblioteca que possui métodos para o fluxo de entra e saída de dados.
#include<iostream>

#include<string>
#include<map>

#include<cstdlib>
/* marcador para uso das funções padrão de C++ = "using namespace std". Seu uso não é aconselhavel por alguns motivos,
   incluindo os debatidos nessa questão no StackOverflow: https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice
*/

// main: Função que guarda todo o código que será executado
// pelo compilador quando abrir este arquivo.
int main(void) {
    // Método para gerar um número aleatório entre 1 e 100;
    srand(time(NULL));
    const int SECRET_NUMBER = (rand() % 100) + 1;


    int guessingNumber;
    bool userIsWrong = true;
    int triesLeft = 5;
    float userPoints = 1000;
    

    // variáveis que ajudam a fazer a conta chegar a 0 caso o usuário digite a pior combinação possível de resultado para cada nível escolhido.
    float multipliedByDifficulty = 0;
    float sumByDifficulty = 0;
    int difficulty;

    // cout é a função padrão do C++ que lida com as saídas de um programa pelo terminal. cin é a função que lida com as entradas do usuário.
    std::cout << "****************************\n";
    std::cout << "Welcome to the guessing game!" << std::endl;
    std::cout << "****************************\n\n";
    std::cout << "First of all, select your difficulty:" << std::endl;
    std::cout << "1. Extreme (3 attemps);" << std::endl;
    std::cout << "2. Hard (5 attemps);" << std::endl;
    std::cout << "3. Medium (8 attemps);" << std::endl;
    std::cout << "4. Easy (12 attemps);" << std::endl;
    std::cout << "5. Very Easy (15 attemps)\n\n";
    
    std::cout << "Option: " << std::endl;
    std::cin >> difficulty;
    std::map<int, bool> numbersTriedByuser;

    // bloco que altera o sistema de pontuação e o número de tentativas de acordo com a dificuldade escolhida pelo usuário.
    switch (difficulty) {
        case 1:
            triesLeft = 3;
            multipliedByDifficulty = 3.4;
            sumByDifficulty = 2.667;
            break;

        case 2:
            triesLeft = 5;
            multipliedByDifficulty = 2.1;
            sumByDifficulty = 7; 
            break;

        case 3:
            triesLeft = 8;
            multipliedByDifficulty = 1.278;
            sumByDifficulty = 1; 
            break;
        
        case 4:
            triesLeft = 12;
            multipliedByDifficulty = 0.857;
            sumByDifficulty = 0.667; 
            break;
        
        case 5:
            triesLeft = 15;
            multipliedByDifficulty = 0.68;
            sumByDifficulty = 0.33339;
            break;

        default:
            throw std::invalid_argument("Insert a integer between 1 and 5 to select difficulty.");
            break;
    }

    // loop para ficar rodando o jogo enquanto o usuario nao acertar e ainda estiver tentativar disponiveis.
    while(userIsWrong and triesLeft) {

        // Pega o numero digitado pelo usuario e em seguida coloca na string de numeros ja escolhidos.
        std::cout << "Type a number between 1 and 100: ";
        std::cin >> guessingNumber;

        if (numbersTriedByuser[guessingNumber]) {
            std::cout << "Sorry, you already tried this number. Try again.\n";
            continue;
        }

        numbersTriedByuser[guessingNumber] = true;

        if (SECRET_NUMBER == guessingNumber) {
            std::cout << "Congrats, You win!" << std::endl;
            std::cout.precision(2);
            std::cout << std::fixed;
            std::cout << "Points: " << userPoints << std::endl;
            userIsWrong = false;
        } else if(guessingNumber > SECRET_NUMBER) {
            --triesLeft;
            std::cout << "Sorry, the number choised was higher than the secret number. You have " << triesLeft << " tries left." << std::endl;
        } else if (guessingNumber < SECRET_NUMBER) {
            --triesLeft;
            std::cout << "Sorry, the number choised was lower than the secret number. You have " << triesLeft << " tries left." << std::endl;
        }

        // Bloco que faz a checagem e altera a pontuação do usuario.
        // se o usuário digitar o número mais longe o possível do correto (numero escolhido = 1; usuário digita 5 vezes o numero 100) resulta em uma pontuação zerada.+
        if(userPoints - abs((SECRET_NUMBER - guessingNumber) * multipliedByDifficulty) + sumByDifficulty < userPoints) {
            userPoints = userPoints - abs((SECRET_NUMBER - guessingNumber) * multipliedByDifficulty) + sumByDifficulty;
        } else {
            userPoints = userPoints - ((userPoints - abs((SECRET_NUMBER - guessingNumber) * multipliedByDifficulty) + sumByDifficulty) - userPoints);
        }
    }

    if(userIsWrong) {
        std::cout.precision(2);
        std::cout << std::fixed;
        std::cout << "Sorry, you lose. Your pontuation was: " << userPoints << std::endl;
    }
}