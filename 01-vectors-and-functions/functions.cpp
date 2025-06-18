#include <iostream>
#include <string>
#include <vector>

void inserirVisitantes(int visitantes, std::string nome_completo, std::vector<std::string>& todosNomes, int idade, std::vector<int>& todasIdades){
    for(int i = 0; i < visitantes; i++){
    std::cout << "Insira o nome do visitante: " << i + 1 << std::endl;
    std::getline(std::cin >> std::ws, nome_completo);
    todosNomes.push_back(nome_completo);

    std::cout << "Insira a idade de " << todosNomes.at(i) << std::endl;
    std::cin >> idade;
    todasIdades.push_back(idade);
    }
}
std::string classificarIdade(int idade){
    std::string classificacao;
    if(idade > 60){
        classificacao = "idoso";
    } else if(idade > 20){
        classificacao = "adulto";
    } else if(idade > 14){
        classificacao = "adolescente";
    } else {
        classificacao = "crianca";
    }
    return classificacao;
}