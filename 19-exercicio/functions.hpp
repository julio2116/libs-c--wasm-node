#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <memory>

class Jogador{
    private:
        std::string nome;
        int vida;
    public:
        Jogador(): nome(""), vida(0) {std::cout << "jogador criado\n";}
        Jogador(std:: string nome, int vida): nome(nome), vida(vida) {std::cout << "jogador " << nome << " criado!\n";}
        ~Jogador(){std::cout << "Jogador " << nome << " destruido!\n";}
        void exibirStatus(){std::cout << "Nome: " << nome << " - vida: " << vida << std::endl;}
};

void addPlayer();
void logoutPlayer();

#endif