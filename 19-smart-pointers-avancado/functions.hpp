#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <map>

class Jogador{
    private:
        std::string nome;
        int vida;
    public:
        Jogador(): nome(""), vida(0) {std::cout << "jogador sem nome criado\n";}
        Jogador(std:: string nome, int vida): nome(nome), vida(vida) {std::cout << "jogador " << nome << " criado!\n";}
        ~Jogador(){std::cout << "Jogador " << nome << " destruido!\n";}
        void exibirStatus(){std::cout << "Nome: " << nome << " - vida: " << vida << std::endl;}
        std::string getNome() const {
            return nome;
        }
};

void addPlayer(std::vector<std::vector<std::shared_ptr<Jogador>>>& sistemas, std::vector<std::weak_ptr<Jogador>>& hud, std::string nome, int vida);
void logoutPlayer(std::vector<std::vector<std::shared_ptr<Jogador>>>& sistemas, std::string nome);
void verifyHud(std::vector<std::weak_ptr<Jogador>> jogadores);

#endif