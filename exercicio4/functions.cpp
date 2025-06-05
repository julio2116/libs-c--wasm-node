#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void writeFile(const std::string& archive, const int& times){
    std::string nome;
    int idade;
    std::vector<std::pair<std::string, int>> nomesIdades;
    std::ofstream arquivo(archive);
    std::cout << "Insira o nome e em seguida a idade das pessoas:" << std::endl;
    for (int i = 0; i < times; i++){
        std::cout << "Insira o nome da pessoa " << i + 1 << std::endl;
        std::getline(std::cin >> std::ws, nome);
        std::cout << "Insira a idade de " << nome << std::endl;
        std::cin >> idade;
        nomesIdades.push_back({nome, idade});
    }
    for(const auto& item : nomesIdades){
        arquivo << "\"" << item.first << "\"," << item.second << "\n";
    }
    arquivo.close();
}
void readFile(const std::string& archive){
    std::string linha;
    int position;
    std::ifstream arquivo(archive);
    std::vector<std::map<std::string, int>> line;
    while (std::getline(arquivo, linha)){
        position = linha.find("-");
        line[linha.substr(linha.begin(), position - 1)] = 5;
        std::cout << linha << std::endl;
    }
    arquivo.close();
}