#include <iostream>
#include <string>
#include <vector>
#include "functions.hpp"

int visitantes;
std::string nome_completo;
std::vector<std::string> todosNomes;
int idade;
std::vector<int> todasIdades;

int main(){
    std::cout << "Quantos visitantes voce quer inserir?" << std::endl;
    std::cin >> visitantes;

    inserirVisitantes(visitantes, nome_completo, todosNomes, idade, todasIdades);

    for(int i = 0; i < visitantes; i++){
        std::cout << todosNomes.at(i) << ": " << classificarIdade(todasIdades.at(i)) << std::endl;
    }
    
    return 0;
}