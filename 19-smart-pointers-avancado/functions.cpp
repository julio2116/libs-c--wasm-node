#include "functions.hpp"

void addPlayer(std::vector<std::vector<std::shared_ptr<Jogador>>>& sistemas, std::vector<std::weak_ptr<Jogador>>& hud, std::string nome, int vida){
    sistemas[0].push_back(std::make_shared<Jogador>(nome, vida));
    if(sistemas.size() > 1){
        for(int i = 1; i < sistemas.size(); i++){
            sistemas[i].push_back(sistemas[0][sistemas[0].size() - 1]);
        }
    }
    hud.push_back(sistemas[0][sistemas[0].size() - 1]);
}
void logoutPlayer(std::vector<std::vector<std::shared_ptr<Jogador>>>& sistemas, std::string nome){
    for(auto& sistema : sistemas){
        for(auto& item : sistema){
            if(item && item->getNome() == nome){
                item.reset();
                item = nullptr;
            }
        }
    }
}

void verifyHud(std::vector<std::weak_ptr<Jogador>> jogadores){
    for(auto jogadorWeak : jogadores){
        if(!jogadorWeak.expired()){
            auto jogador = jogadorWeak.lock();
            std::cout << "hud verifica " << jogador->getNome() << ": VIVO" << std::endl;
        } else {
            std::cout << "Hud verifica: MORTO" << std::endl;
        }
    }
}