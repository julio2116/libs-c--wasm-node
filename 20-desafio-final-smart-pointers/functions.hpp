#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <memory>
#include <vector>

class Jogador{
    private:
        std::string nome;
        int vida;
    public:
        Jogador(): nome(""), vida(0){std::cout << "Jogadr sem nome criado!\n";}
        Jogador(std::string nome, int vida): nome(nome), vida(vida){std::cout << "Jogador " << nome << " criado!\n";}
        ~Jogador(){std::cout << "Jogador " << nome << " destruido!\n";}
        void receberDano(int dano){
            vida -= dano;
        }
        int exibirStatus(){
            return vida;
        }
        std::string getNome(){
            return nome;
        }
        int atacar(){
            return 10;
        }
};

class Game{
    private:
        std::vector<std::vector<std::shared_ptr<Jogador>>> game;
        std::vector<std::weak_ptr<Jogador>> hud;
    public:
        Game(): game(){std::cout << "Novo game iniciado\n";}

        void inserirSistema(std::vector<std::shared_ptr<Jogador>>& sistema){
            game.push_back(sistema);
        }

        std::shared_ptr<Jogador> inserirJogador(const std::string& nome, const int& vida){
            game[0].push_back(std::make_shared<Jogador>(nome, vida));
            if(game.size() > 1){
                for(int i = 1; i < game.size(); i++){
                    game[i].push_back(game[0][game[0].size() - 1]);
                }
            }
            hud.push_back(game[0][game[0].size() - 1]);
            return game[0][game[0].size() - 1];
        }

        void removerJogador(const std::string& nome){
            for(auto& sistema : game){
                for(auto& item : sistema){
                    if(item && item->getNome() == nome){
                        item.reset();
                        item = nullptr;
                    }
                }
            }
        }

        void vericarJogador(){
            for(auto& jogadorWeak : hud){
                if(!jogadorWeak.expired()){
                    auto jogador = jogadorWeak.lock();
                    std::cout << "Jogador " << jogador->getNome() << " esta vivo!\n";
                } else {
                    std::cout << "Jogador esta morto!\n";
                }
            }
        }
};

void realizarAtaque(std::unique_ptr<Game>& newGame, std::shared_ptr<Jogador>& atacante, std::shared_ptr<Jogador>& atacado);

#endif