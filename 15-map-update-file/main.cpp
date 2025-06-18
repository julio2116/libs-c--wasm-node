#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int main(){
    std::string nomeBuscado;
    std::map<std::string, int> nomesIdades;
    std::fstream arquivo("usuarios.txt", std::ios::in | std::ios::app);
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir arquivo\n";
        return 1;
    }

    std::cout << "Insira o nome da pessoa\n";
    std::getline(std::cin, nomeBuscado);

    std::string linha;
    while(std::getline(arquivo, linha)){
        int posicao = linha.find(",");
        if(posicao  == std::string::npos){
            continue;
        }
        std::string nome = linha.substr(0, posicao);
        int idade = stoi(linha.substr(posicao + 1));
        nomesIdades[nome] = idade;
    }
    
    for(auto& [nome, idade] : nomesIdades){
        if(nome != nomeBuscado){
            continue;
        }

        std::cout << "Insira a nova idade:\n";
        std::cin >> nomesIdades[nome];

        if(std::cin.fail()){
            std::cout << "entrada de idade inválida insira um numero, maior que zero";
            return 1;
        }
    }

    std::ofstream novoArquivo("usuarios.txt", std::ios::trunc);

    if(!novoArquivo.is_open()){
        std::cerr << "Erro ao abrir o arquivo\n";
        return 1;
    }

    for(const auto& [nome, idade] : nomesIdades){
        novoArquivo << nome << "," << idade << "\n";
    }

    return 0;
}