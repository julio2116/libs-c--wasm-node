#include "functions.hpp"
    
int main(){
    std::vector<std::shared_ptr<Jogador>> jogadoresAtivos;
    std::vector<std::shared_ptr<Jogador>> sistemaCombate;
    std::vector<std::shared_ptr<Jogador>> sistemaRede;
    std::vector<std::weak_ptr<Jogador>> hudJogadores;
    std::vector<std::vector<std::shared_ptr<Jogador>>> sistemas;
    sistemas.push_back(jogadoresAtivos);
    sistemas.push_back(sistemaCombate);
    sistemas.push_back(sistemaRede);

    addPlayer(sistemas, hudJogadores, "julio", 100);
    addPlayer(sistemas, hudJogadores, "Teste", 200);

    verifyHud(hudJogadores);
    
    logoutPlayer(sistemas, "julio");
    
    verifyHud(hudJogadores);

    return 0;
}