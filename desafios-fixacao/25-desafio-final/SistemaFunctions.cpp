#include "functions.hpp"

void Sistema::inserirSistema(std::string sistema){
    if(std::find(sistemas.begin(), sistemas.end(), sistema) != sistemas.end()){
        throw std::invalid_argument("Sistema já incluído!");
    }
    for(auto& [sistema, jogador] : hud){
        if(hud.find(sistema) == hud.end() || !jogador.expired()){
            throw std::invalid_argument("Impossível incluir um novo sistema com jogadores logados!");
        }
    }
    sistemas.push_back(sistema);
}

void Sistema::realizarLogin(std::string nomeJogador, int vida){
    for(auto& jogador : hud){
        if(hud.find(nomeJogador) != hud.end()){
            throw std::invalid_argument("Jogador " + nomeJogador + " ja esta logado\n");
        }
    }
    jogadoresSistema[];
}

void Sistema::realizarLogout(std::string nomeJogador){

}

void Sistema::combate(std::string atacante, std::string alvo, int dano){

}

void Sistema::inserirMissao(std::string nomeJogador, std::string nomeMissao){

}

void Sistema::verificarStatusHUD(std::string nomeJogador){

}

void Sistema::exibirTodosJogadores(){

}

void Sistema::verificarMissoes(std::string nomeJogador){

}
