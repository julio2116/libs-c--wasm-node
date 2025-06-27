#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <map>
#include <memory>

class Jogador{
    private:
        std::vector<std::string> listaMissoes;
        std::string nome;
        int vida;
    public:
        Jogador(std::string nome, int vida):nome(nome), vida(vida){std::cout << "Jogador " << nome << " criado!\n";}
        ~Jogador(){std::cout << "Jogador " << nome << " destruido!\n";}

        void receberDano(int dano){vida -= dano;}
        void adicionarMissao(std::string missao){listaMissoes.push_back(missao);}
        int status(){return vida;}
        std::string getNome(){return nome;}
        std::vector<std::string> listarMissoes(){
            return listaMissoes;
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

        void RealizarLogin(std::string nome, int vida);
        void inserirSistema(std::string sistema);
        void realizarLogout(std::string nome);
        void verificarStatusJogadores();
        void combate(std::string atacanteNome, std::string atacadoNome, int dano);
        void inserirMissao(std::string jogador, std::string missao);
        void verificarMissoes(std::string nome);
};

#endif