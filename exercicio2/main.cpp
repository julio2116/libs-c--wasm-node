#include <iostream>
#include <vector>
#include <string>
#include "functions.hpp"

int main(){
    int visitantes;
    std::vector<std::string> todos_nomes;
    std::vector<int> todas_idades;
    
    std::cout << "Quantos visitantes quer cadastrar?" << std::endl;
    std::cin >> visitantes;
    
    inserirVisitantes(visitantes, todos_nomes, todas_idades);
    filtrarVisitantes(visitantes, todos_nomes, todas_idades);
    return 0;
}