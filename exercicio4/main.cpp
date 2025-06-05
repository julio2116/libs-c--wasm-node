#include <iostream>
#include <string>
#include <fstream>
#include "functions.hpp"

int main(){
    std::string dados = "dados.txt";
    int times;

    std::cout << "Quantas pessoas deseja incluir?" << std::endl;
    std::cin >> times;

    writeFile(dados, times);
    readFile(dados);

    return 0;
}