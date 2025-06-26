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
        std::vector<std::string> listaMissoes;
    public:
        Jogador(std::string nome, int vida):nome(nome), vida(vida){std::cout << "Jogador " << nome << " criado!\n";}
        ~Jogador(){std::cout << "Jogador " << nome << " destruido!\n";}

        void receberDano(int dano){
            vida -= dano;
        }
        void adicionarMisaao(std::string missao){
            listaMissoes.push_back(missao);
        }
        int status(){
            return vida;
        }
};

class Sistema{
    private:
        std::map<std::string, std::map<std::string, std::shared_ptr<Jogador>>> jogadoresLogados;
        std::map<std::string, std::weak_ptr<Jogador>> hud;
        std::vector<std::string> sistemas;

    public:
        Sistema():jogadoresLogados(), hud(), sistemas(){std::cout << "Novo sistema iniciado!\n";}
        ~Sistema(){std::cout << "Sistema encerrado!\n";}

        void RealizarLogin(std::string nome, int vida){
            std::shared_ptr<Jogador> jogador = std::make_shared<Jogador>(jogador, vida);

            if(sistemas.size() > 0){
                if(jogadoresLogados.at(sistemas[0]).count(nome) > 0){
                    return;
                }
                for(auto& sistema : sistemas){
                    jogadoresLogados.at(sistema).at(nome) = jogador;
                }
                hud.insert({nome, jogador});

                jogador.reset();
                jogador = nullptr;
            } else {
                throw std::invalid_argument("Não existem sistemas ativos para logar o jogador!\n");
            }
        }

        void inserirSistema(std::string sistema){
            if(){
                std::invalid_argument("Impossivel inserir novos sistemas enquanto houverem jogadores logados!\n");
            }
            for(auto& jogador : hud){
                if(!jogador.second.expired() || ){
                    std::invalid_argument("Impossivel inserir novos sistemas enquanto houverem jogadores logados!\n");
                } else {
                    sistemas.push_back(sistema);
                }
            }
        }

        void realizarLogout(std::string nome){
            if(jogadoresLogados.at(sistemas[0]).count(nome) > 0 || sistemas.size() <= 0){
                return;
            }
            for(auto& sistema : sistemas){
                jogadoresLogados.at(sistema).at(nome).reset();
                jogadoresLogados.at(sistema).at(nome) = nullptr;
            }
        }
};

#endif