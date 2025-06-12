#include "functions.hpp"

int main(){
    std::map<faixaEtaria, std::vector<std::string>> nomesEFaixa;
    std::vector<std::pair<std::string, int>> nomesEIdades;
    const std::string arquivo = "catalogo.csv";
    
    initialFunction(nomesEIdades);
    writeFile(nomesEIdades, arquivo);
    writeOutputObject(nomesEFaixa, arquivo);
    printResult(nomesEFaixa);

    return 0;
}