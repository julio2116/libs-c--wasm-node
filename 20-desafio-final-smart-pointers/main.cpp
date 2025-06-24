#include "functions.hpp"

int main(){
    std::unique_ptr<Game> newGame = std::make_unique<Game>();

    std::vector<std::shared_ptr<Jogador>> jogadores;
    std::vector<std::shared_ptr<Jogador>> sistemaCombate;
    std::vector<std::shared_ptr<Jogador>> sistemaRede;

    newGame->inserirSistema(jogadores);
    newGame->inserirSistema(sistemaCombate);
    newGame->inserirSistema(sistemaRede);

    std::shared_ptr<Jogador> player1 = newGame->inserirJogador("Julio", 100);
    std::shared_ptr<Jogador> player2 = newGame->inserirJogador("Maria", 100);
    std::shared_ptr<Jogador> player3 = newGame->inserirJogador("Paulo", 100);
    
    for(int i = 0; i < 10; i++){
        realizarAtaque(newGame, player1, player2);
    }

    return 0;
}