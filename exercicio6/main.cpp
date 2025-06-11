#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <map>

void validateNumber(int &number, const std::string &message){
    bool next = true;
    while (next){
        std::cin >> number;
        if (std::cin.fail() || number < 1){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << message << "\n";
        } else {
            next = false;
        }
    }
}
enum faixaEtaria{
    CRIANCAS,
    ADOLESCENTES,
    ADULTOS
};

std::string converterFaixa(faixaEtaria faixa){
    switch (faixa)
    {
    case CRIANCAS:
        return "== CRIANCAS ==";
    case ADOLESCENTES:
        return "== ADOLESCENTES ==";
    case ADULTOS:
        return "== ADULTOS ==";
    default:
        return "== DESCONHECIDO ==";
    }
}
faixaEtaria classificarIdade(int idade){
    if (idade >= 18){
        return ADULTOS;
    } else if (idade >= 13){
        return ADOLESCENTES;
    } else {
        return CRIANCAS;
    }
}

int main(){
    int usersQtd;
    std::cout << "Quantos usuarios deseja cadastrar?\n";
    std::vector<std::pair<std::string, int>> nomesEIdades;

    validateNumber(usersQtd, "Insira um numero maior que 0!");

    for (auto i = 0; i < usersQtd; i++){
        int idade;
        std::string name;
        std::cout << "Insira o nome da pessoa " << i + 1 << "\n";
        std::getline(std::cin >> std::ws, name);

        std::cout << "Qual a idade de " << name << "?\n";
        validateNumber(idade, "Insira uma idade valida, numeros maiores que 0!");

        nomesEIdades.push_back({name, idade});
    }

    std::ofstream arquivo("catalogo.csv");

    if (arquivo.is_open()){
        for (auto const &item : nomesEIdades){
            arquivo << "\"" << item.first << "\"," << item.second << "\n";
        }
    }
    arquivo.close();

    std::ifstream arquivo2("catalogo.csv");
    std::string linha;
    int idade;
    std::map<faixaEtaria, std::vector<std::string>> nomesEFaixa;

    if (arquivo2.is_open()){
        while (std::getline(arquivo2, linha)){
            int posicao = linha.find(",");
            std::string nomeAspas = linha.substr(0, posicao);
            std::string nome = nomeAspas.substr(1, posicao - 2);
            try{
                idade = stoi(linha.substr(posicao + 1));
            }
            catch (const std::invalid_argument &e){
                std::cerr << "Erro na conversao de numeros" << "\n";
            }

            faixaEtaria faixa =  classificarIdade(idade);
            nomesEFaixa[faixa].push_back(nome);
        }
    }
    
    for (auto const &item : nomesEFaixa){
        std::string message = converterFaixa(item.first);
        std::cout << message << "\n";
        for (auto const &itemInterno : nomesEFaixa[item.first]){
            std::cout << itemInterno << "\n";
        }
    }

    return 0;
}