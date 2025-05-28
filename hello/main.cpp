#include <iostream>
#include <string>
#include "funcoes.hpp"

int idade = 28;
std::string nome;

int main(){
    std::cout << "DIgite seu nome completo:" << std::endl;
    std::getline(std::cin >> std::ws, nome);

    mostrarSaudacao(nome);

    return 0;
}