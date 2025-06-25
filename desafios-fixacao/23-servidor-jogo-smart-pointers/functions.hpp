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
        Jogador(std::string nome, int vida):nome(nome), vida(vida){std::cout << "Jogador: " << nome << " criado!\n";}
        ~Jogador(){std::cout << "Jogador: " << nome << " destruido!\n";}

        void receberDano(int dano){vida -= dano;}
        
        void exibirStatus(){
            std::cout << "[" << nome << "] Status: vida " << vida << std::endl;
        }
};

class Servidor{
    private:
        std::map<std::string, std::map<std::string, std::shared_ptr<Jogador>>> jogadores;
        std::vector<std::string> sistemas;
        std::map<std::string, std::weak_ptr<Jogador>> hud;

        public:
        Servidor():jogadores(), hud(){std::cout << "Servidor inicializado\n";}
        
        void conectarJogador(std::string nome, int vida){
            std::shared_ptr<Jogador> jogador = std::make_shared<Jogador>(nome, vida);
            if(sistemas.size() > 0){
                for(auto& sistema : sistemas){
                    jogadores[sistema].insert({nome, jogador});
                }
                hud[nome] = jogador;
            } else {
                throw std::invalid_argument("Impossível efetuar login sem um criar um sistema antes!");
            }
        }
        
        void logoutJogador(std::string nome){
            if(jogadores.size() > 0){
                for(auto& sistema : sistemas){
                    std::shared_ptr<Jogador> identificador = jogadores[sistema][nome];
                    if(identificador){
                        jogadores[sistema][nome].reset();
                        jogadores[sistema][nome] = nullptr;
                    } else {
                        throw std::invalid_argument("O jogador " + nome + " nao esta logado no sistema!\n");
                    }
                }
                std::cout << nome << " deslogou!\n";
            } else {
                throw std::invalid_argument("Ainda não foram inseridos nenhum sistema, para que seja realizado logout de jogadores!");
            }
        }

        void inserirSistema(std::string sistema){
            sistemas.push_back(sistema);
        }

        void verificacaoHud(std::string nome){
            if(!hud[nome].expired()){
                    auto jogador = hud[nome].lock();
                    std::cout << "HUD verifica " << nome << ": VIVO\n";
            } else {
                std::cout << "HUD verifica " << nome << ": MORTO\n";
            }
        }

        void exibirTodosStatus(){
            for(auto& jogador: hud){
                if(!hud[jogador.first].expired()){
                    auto jogador_ptr = hud[jogador.first].lock();
                    jogador_ptr->exibirStatus();
                }
            }
        }

};

#endif