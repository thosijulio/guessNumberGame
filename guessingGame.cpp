/*
    Padrao para adição de bibliotecas em C++: 
        "#include" e o nome da biblioteca que será utilizada entre "<>"
*/
// iostream é uma biblioteca que possui métodos para o fluxo de entra e saída de dados.
#include<iostream>
/* marcador para uso das funções padrão de C++ = "using namespace std". Seu uso não é aconselhavel por alguns motivos,
   incluindo os debatidos nessa questão no StackOverflow: https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice
*/

// main: Função que guarda todo o código que será executado
// pelo compilador quando abrir este arquivo.
int main(void){
    // cout é a função padrão do C++ que lida com as saídas de um programa pelo terminal. cin é a função que lida com as entradas do usuário.
    std::cout << "****************************\n";
    std::cout << "Welcome to the guessing game" << std::endl;
    std::cout << "****************************\n\n";

    const int SECRET_NUMBER = 42;
    int guessingNumber;
    bool userIsWrong = true;

    while(userIsWrong) {

        std::cout << "Type a number between 1 and 100: ";
        std::cin >> guessingNumber;
        if(SECRET_NUMBER == guessingNumber) {
        std::cout << "Congrats, You win!" << std::endl;
        userIsWrong = false;
        } else if(guessingNumber > SECRET_NUMBER) {
            std::cout << "Sorry, the number choised was higher than the secret number. Try again" << std::endl;
        } else if (guessingNumber < SECRET_NUMBER) {
            std::cout << "Sorry, the number choised was lower than the secret number. Try again." << std::endl;
        }
    }
}