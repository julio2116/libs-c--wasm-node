#include "functions.hpp"

int main(){
    std::map<faixaEtaria, std::vector<std::string>> nomesEFaixa;
    std::vector<std::pair<std::string, int>> nomesEIdades;
    const std::string arquivo = "catalogo.csv";
    
    try{
        initialFunction(nomesEIdades);
        writeFile(nomesEIdades, arquivo);
        writeOutputObject(nomesEFaixa, arquivo);
        printResult(nomesEFaixa);
    } catch (const std::exception &e){
        std::cout << "Erro na execucao do programa: " << e.what() << "\n";
    }

    return 0;
}