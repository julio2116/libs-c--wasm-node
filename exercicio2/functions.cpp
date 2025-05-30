#include <iostream>
#include <string>
#include <vector>

void inserirVisitantes(int visitantes, std::vector<std::string> &todos_nomes, std::vector<int> &todas_idades){
    int i = 0;
    std::string name;
    int idade;

    while (i < visitantes){
        std::cout << "Insira o nome do visitante " << i + 1 << ":" << std::endl;
        std::getline(std::cin >> std::ws, name);
        todos_nomes.push_back(name);

        std::cout << "Insira a idade de " << todos_nomes.at(i) << std::endl;
        std::cin >> idade;
        todas_idades.push_back(idade);
        i++;
    }
}

void filtrarVisitantes(int visitantes, std::vector<std::string>& todos_nomes, std::vector<int>& todas_idades){
    int filter;
    std::cout << "Digite a idade minima para filtrar os visitantes:" << std::endl;
    std::cin >> filter;
    std::cout << "Visitantes com idade igual ou superior a " << filter << ":" << std::endl;
    for (int j = 0; j < visitantes; j++){
        if (todas_idades.at(j) >= filter){
            std::cout << "- " << todos_nomes.at(j) << std::endl;
        }
    }
}