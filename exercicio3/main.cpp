#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "functions.hpp"

int main(){
    int qtd;
    std::vector<int> idades;
    int idade;
    std::map<std::string, int> groups;
    std::string faixa;

    std::cout << "Quantas classificacoes devem ser feitas?" << std::endl;
    std::cin >> qtd;
    for(int i = 0; i < qtd; i++){
        std::cout << "Insira a idade da pessoa " << i + 1 << std::endl;
        std::cin >> idade;
        idades.push_back(idade);
    }
    for(int i = 0; i < idades.size(); i++){
        FaixaEtaria classificacao = classificarEnum(idades.at(i));
        faixa = faixaEtariaParaTexto(classificacao);
        groups[faixa] += 1;
    }
    for(auto group : groups){
        std::cout << group.first << " = " << group.second << std::endl;
    }
    return 0;
}