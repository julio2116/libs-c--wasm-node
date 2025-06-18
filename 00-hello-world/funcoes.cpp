#include <iostream>
#include "funcoes.hpp"
#include <string>

void mostrarSaudacao(std::string nome){
    std::cout << "Bem vindo, " << nome << std::endl;
}

int somar(int a, int b){
    return a + b;
}