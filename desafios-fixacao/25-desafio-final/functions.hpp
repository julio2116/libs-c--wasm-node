#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <map>

class Jogador{
    private:
        std::string nome;
        int vida;
        std::vector<std::string> listaMissoes;
    public:
        Jogador(std::string nome, int vida): nome(nome), vida(vida){ std::cout << "Jogador: " << nome << " criado\n"; }
        ~Jogador(){std::cout << "Jogador: " << nome << " destruido!\n";}

        void receberDano(int dano) { vida -= dano; }
        int getStatus(){ return vida; }
        std::string getNome(){ return nome; }
        void adicionarMissao(std::string missao);
        void listarMissoes();
};

class Sistema{
    private:
        std::map<std::string, std::map<std::string, std::shared_ptr<Jogador>>> jogadoresSistema;
        std::map<std::string, std::weak_ptr<Jogador>> hud;
        std::vector<std::string> sistemas;
    public:
        Sistema():jogadoresSistema(), sistemas(), hud() { std::cout << "Novo Sistema criado!\n"; }
        ~Sistema(){ std::cout << "Sistema finalizado\n"; }
        void inserirSistema(std::string sistema);
        void realizarLogin(std::string nomeJogador, int vida);
        void realizarLogout(std::string nomeJogador);
        void combate(std::string atacante, std::string alvo, int dano);
        void inserirMissao(std::string nomeJogador, std::string nomeMissao);
        void verificarStatusHUD(std::string nomeJogador);
        void exibirTodosJogadores();
        void verificarMissoes(std::string nomeJogador);
};

#endif