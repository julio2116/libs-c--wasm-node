#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <map>
#include <memory>

class Jogador{
    private:
        std::string nome;
        int vida;
    public:
        Jogador(std::string nome, int vida):nome(nome), vida(vida){std::cout << "Jogador: " << nome << "criado!\n";}
        ~Jogador(){std::cout << "Jogadort: " << nome << " destruido!\n";}

        void receberDano(int dano){vida -= dano;}
        
        void exibirStatus(){
            std::cout << "Jogador: " << nome << " , vida: " << vida << std::endl;
        }
};

class Servidor{
    private:
        std::map<std::string, std::map<std::string, std::shared_ptr<Jogador>>> jogadores;
        std::vector<std::string> sistemas;
        std::vector<std::weak_ptr<Jogador>> hud;

        public:
        Servidor():jogadores(), hud(){std::cout << "Servidor inicializado\n";}
        
        void conectarJogador(std::string nome, int vida){
            std::shared_ptr<Jogador> jogador = std::make_shared<Jogador>(nome, vida);
            if(jogadores.size() > 0){
                for(auto& sistema : sistemas){
                    jogadores.at(sistema).insert({nome, jogador});
                }
            } else {
                throw std::invalid_argument("Impossível efetuar sem um criar um sistema antes!");
            }
        }

        void logoutJogador(std::string nome){

        }

        void InserirSistema(std::string sistema){
            sistemas.push_back(sistema);
        }

};

#endif