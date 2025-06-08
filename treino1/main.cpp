#include <iostream>
#include <vector>

int main(){
    int qtd;
    std::cout << "Quantas notas deseja inserir para calcular a media?" << std::endl;
    std::cin >> qtd;
    std::vector<int> notas;
    int nota;
    int todasNotas;

    for(int i = 0; i < qtd; i++){
        std::cout << "Insira a nota" << i + 1 << ":" << std::endl;
        std::cin >> nota;
        notas.push_back(nota);
    }
    for(int i = 0; i < notas.size(); i++){
        todasNotas = todasNotas + notas.at(i);
    }
    int media = todasNotas / qtd;

    std::cout << "A media e de: " << media << std::endl;

    return 0;
}