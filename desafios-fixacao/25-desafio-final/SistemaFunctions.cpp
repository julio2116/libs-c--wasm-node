#include "functions.hpp"

void Sistema::inserirSistema(std::string sistema){
    if(std::find(sistemas.begin(), sistemas.end(), sistema) != sistemas.end()){
        throw std::invalid_argument("Sistema ja incluido!");
    }
    for(const auto& [nome, jogador] : hud){
        if(!jogador.expired()){
            throw std::invalid_argument("Impossivel incluir um novo sistema com jogadores ativos!");
        }
    }
    sistemas.push_back(sistema);
}

void Sistema::realizarLogin(std::string nomeJogador, int vida){
    if(hud.find(nomeJogador) != hud.end()){
        throw std::invalid_argument("Jogador " + nomeJogador + " ja esta logado\n");
    }

    std::shared_ptr<Jogador> jogador = std::make_shared<Jogador>(nomeJogador, vida);
    for(const auto& sistema : sistemas){
        jogadoresSistema[sistema][nomeJogador] = jogador;
    }
    hud[nomeJogador] = jogador;
}

void Sistema::realizarLogout(std::string nomeJogador){
    if(hud.find(nomeJogador) == hud.end()){
        throw std::invalid_argument("Jogador nao esta logado no sistema\n");
    }
    if(!hud.at(nomeJogador).expired()){
        auto jogador = hud.at(nomeJogador).lock();
        for(auto& sistema : sistemas){
            jogadoresSistema.at(sistema).erase(nomeJogador);

        }
    }
}

void Sistema::combate(std::string atacante, std::string alvo, int dano){
    auto itAtacante = hud.find(atacante);
    if(itAtacante == hud.end() || itAtacante->second.expired()){
        throw std::invalid_argument("Jogador " + atacante + " não é um jogador valido, para combates\n");
    }
    auto itAlvo = hud.find(alvo);
    if(itAlvo == hud.end() || itAlvo->second.expired()){
        throw std::invalid_argument("Jogador " + alvo + " não é um jogador valido, para combates\n");
    }
    auto jogadorAlvo = itAlvo->second.lock();
    jogadorAlvo->receberDano(dano);
    if(jogadorAlvo->getStatus() <= 0){
        realizarLogout(alvo);
    }
}

void Sistema::inserirMissao(std::string nomeJogador, std::string nomeMissao){
    auto itJogador = hud.find(nomeJogador);
    if(itJogador == hud.end() || itJogador->second.expired()){
        throw std::invalid_argument("impossivel adicionar missoes ao jogador " + nomeJogador + "\n");
    }
    auto jogador = itJogador->second.lock();
    jogador->adicionarMissao(nomeMissao);
}

void Sistema::verificarStatusHUD(std::string nomeJogador){
    auto itJogador = hud.find(nomeJogador);
    if(itJogador == hud.end()){
        throw std::invalid_argument("Jogador " + nomeJogador + " nao esta logado\n");
    }
    if(itJogador->second.expired()){
        std::cout << "Jogador " << nomeJogador << " esta morto\n";
    } else {
        std::cout << "Jogador " << nomeJogador << " esta vivo\n";
    }
}

void Sistema::exibirTodosJogadores(){
    if(hud.size() < 1){
        throw std::invalid_argument("Nao existem jogadores no hud\n");
    }
    for(auto& jogador : hud){
        if(!jogador.second.expired()){
            auto itJogador = jogador.second.lock();
            std::cout << "[" << itJogador->getNome() << "] Status: vida " << itJogador->getStatus() << "\n";
        }
    }
}

void Sistema::verificarMissoes(std::string nomeJogador){
    auto itJogador = hud.find(nomeJogador);
    if(itJogador == hud.end() || itJogador->second.expired()){
        throw std::invalid_argument("Jogador " + nomeJogador + " nao e uma escolha valida\n");
    }
    auto jogador = itJogador->second.lock();

    std::cout << "Missoes do jogador " << nomeJogador << ":\n";
    if(jogador->listarMissoes().size() < 1){
        std::cout << " (nenhuma missao atribuida)\n";
    } else {
        for(const auto& missao : jogador->listarMissoes()){
            std::cout << " - " << missao << "\n";
        }
    }
}
