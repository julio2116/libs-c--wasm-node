#include "functions.hpp"

int main(){
    int fases;
    int* dados = nullptr;
    std::cout << "Quantas fases o jogador completou?\n";
    std::cin >> fases;
    std::cout << "Insira as pontuacoes das fases:\n";
    
    alocarFases(&dados, fases);
    
    std::cout << "Pontuacoes antes de dobrar:\n";
    
    imprimirFases(dados, fases);
    
    dobrarPontuacoes(dados, fases);

    std::cout << "Pontuacoes depois de dobrar:\n";

    imprimirFases(dados, fases);

    delete[] dados;
    dados = nullptr;

    return 0;
}