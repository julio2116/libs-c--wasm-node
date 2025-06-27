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
            throw std::invalid_argument("Impossivel inserir novos sistemas enquanto houverem jogadores logados!\n");
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
        throw std::invalid_argument("Jogador: " + nome + " não logou no sistema!\n");
    }
    if (hud[nome].expired()){
        throw std::invalid_argument("Jogador: " + nome + " já realizou logout!\n");
    }
    for (auto &sistema : sistemas){
        jogadoresLogados[sistema][nome].reset();
        jogadoresLogados[sistema][nome] = nullptr;
    }
    hud.erase(nome);
}

void Sistema::verificarStatusJogadores(){
    for (const auto &[nome, jogador] : hud){
        std::cout << "Jogador: " << nome << " esta " << (jogador.expired() ? "morto" : "vivo") << "\n";
    }
}

void Sistema::combate(std::string atacanteNome, std::string atacadoNome, int dano){
    if (hud[atacanteNome].expired() || hud.count(atacanteNome) < 1){
        throw std::invalid_argument("O atacante nao esta no sistema");
    }
    if (hud[atacadoNome].expired() || hud.count(atacadoNome) < 1){
        throw std::invalid_argument("O atacado nao esta no sistema");
    }
    
    auto atacante = hud.at(atacanteNome).lock();
    auto atacado = hud.at(atacadoNome).lock();
    
    atacado->receberDano(dano);
    
    std::cout << atacante->getNome() << " ataca " << atacado->getNome() << " causando " << dano << " de dano!\n";

    if (atacado->status() <= 0){
        for (auto &sistema : sistemas){
            jogadoresLogados.at(sistema).at(atacadoNome).reset();
            jogadoresLogados.at(sistema).at(atacadoNome) = nullptr;
        }
    }
}

void Sistema::inserirMissao(std::string nome, std::string missao){
    if (hud[nome].expired()){
        throw std::invalid_argument("Jogador " + nome + " não esta logado!\n");
    }
    auto jogador = hud.at(nome).lock();
    jogador->adicionarMissao(missao);
}

void Sistema::verificarMissoes(std::string nome){
    if (hud[nome].expired()){
        throw std::invalid_argument("Jogador " + nome + " não esta logado!\n");
    }
    auto jogador = hud.at(nome).lock();
    std::cout << "Missoes do jogador " << nome << ":\n";

    for(const auto& missao : jogador->listarMissoes()){
        std::cout << missao << "\n";
    }
}