#include <iostream>
#include <string>
#include <fstream>

void writeFile(const std::string& archive){
    std::string nome;
    int idade;
    std::ofstream arquivo(archive);
    std::cout << "Insira o nome e em seguida a idade de 3 pessoas:" << std::endl;
    for (int i = 0; i < 3; i++){
        std::cout << "Insira o nome da pessoa " << i + 1 << std::endl;
        std::getline(std::cin >> std::ws, nome);
        std::cout << "Insira a idade de " << nome << std::endl;
        std::cin >> idade;
        arquivo << nome << ", " << idade << "\n";
    }
    arquivo.close();
}
void readFile(const std::string& archive){
    std::string linha;
    std::ifstream arquivo(archive);
    while (std::getline(arquivo, linha)){
        std::cout << linha << std::endl;
    }
    arquivo.close();
}