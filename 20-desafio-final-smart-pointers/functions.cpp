#include "functions.hpp"

void realizarAtaque(std::unique_ptr<Game>& newGame, std::shared_ptr<Jogador>& atacante, std::shared_ptr<Jogador>& atacado){
    int dano = atacante->atacar();
    atacado->receberDano(dano);
    std::cout << atacante->getNome() << " ataca " << atacado->getNome() << "(" << dano << " de dano)\n";
    if(atacado->exibirStatus() <= 0){
        newGame->removerJogador(atacado->getNome());
        atacado.reset();
        atacado = nullptr;
        newGame->vericarJogador();
    }
}