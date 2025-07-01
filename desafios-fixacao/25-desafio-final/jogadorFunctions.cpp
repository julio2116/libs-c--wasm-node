#include "functions.hpp"

void Jogador::adicionarMissao(std::string missao){
    listaMissoes.push_back(missao);
}
void Jogador::listarMissoes(){
    if(listaMissoes.size() > 0){
        for(auto& missao : listaMissoes){
            
        }
    } else {
        throw std::invalid_argument("Não existem missoes para o jogador " + nome);
    }
}