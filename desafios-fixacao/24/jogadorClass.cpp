#include "functions.hpp"

void Sistema::RealizarLogin(std::string nome, int vida){
    if (sistemas.size() > 0){
        if (hud.count(nome) > 0){
            return;
        }
        std::shared_ptr<Jogador> jogador = std::make_shared<Jogador>(nome, vida);
        for (auto &sistema : sistemas){
            jogadoresLogados[sistema][nome] = jogador;
        }
        hud.insert({nome, jogador});

        jogador.reset();
        jogador = nullptr;
    } else {
        throw std::invalid_argument("Não existem sistemas ativos para logar o jogador!\n");
    }
}

void Sistema::inserirSistema(std::string sistema){
    for (auto &jogador : hud){
        if (!jogador.second.expired()){
            std::invalid_argument("Impossivel inserir novos sistemas enquanto houverem jogadores logados!\n");
        } else {
            sistemas.push_back(sistema);
        }
    }
    if(sistemas.size() < 1){
        sistemas.push_back(sistema);
    }
}

void Sistema::realizarLogout(std::string nome){
    if (hud.count(nome) > 0){
        std::invalid_argument("Jogador: " + nome + " não logou no sistema!\n");
    }
    if (hud[nome].expired()){
        std::invalid_argument("Jogador: " + nome + " já realizou logout!\n");
    }
    for (auto &sistema : sistemas){
        jogadoresLogados[sistema][nome].reset();
        jogadoresLogados[sistema][nome] = nullptr;
    }
}

void Sistema::verificarStatusJogadores(){
    for (const auto &[nome, jogador] : hud){
        std::cout << "Jogador: " << nome << " esta " << (jogador.expired() ? "morto" : "vivo") << "\n";
    }
}

void Sistema::combate(std::string atacanteNome, std::string atacadoNome, int dano){
    if (hud[atacanteNome].expired()){
        std::invalid_argument("O atacante não esta no sistema");
    }
    if (hud[atacadoNome].expired()){
        std::invalid_argument("O atacado não esta no sistema");
    }
    
    auto atacante = hud[atacanteNome].lock();
    auto atacado = hud[atacadoNome].lock();
    
    atacado->receberDano(dano);
    std::cout << "teste\n";
    
    std::cout << atacante->getNome() << " ataca " << atacado->getNome() << " causando " << dano << "de dano!\n";
    std::cout << "teste 2\n";

    if (atacado->status() <= 0){
        for (auto &sistema : sistemas){
            jogadoresLogados[sistema][atacadoNome].reset();
            jogadoresLogados[sistema][atacadoNome] = nullptr;
        }
    }
}