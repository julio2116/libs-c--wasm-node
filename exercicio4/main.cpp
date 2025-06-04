#include <iostream>
#include <string>
#include <fstream>
#include "functions.hpp"

int main(){
    std::string dados = "dados.txt";

    writeFile(dados);
    readFile(dados);

    return 0;
}