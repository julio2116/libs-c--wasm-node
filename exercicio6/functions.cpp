#include "functions.hpp"

void initialFunction(std::vector<std::pair<std::string, int>> &nomesEIdades){
    int usersQtd;
    std::cout << "Quantos usuarios deseja cadastrar?\n";
    
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
}

void writeFile(const std::vector<std::pair<std::string, int>> &nomesEIdades, const std::string &arquivoRecebido){
    std::ofstream arquivo(arquivoRecebido);

    if (arquivo.is_open()){
        for (auto const &item : nomesEIdades){
            arquivo << "\"" << item.first << "\"," << item.second << "\n";
        }
    } else {
        std::cout << "Erro ao abrir arquivo\n";
    }
    arquivo.close();
}

void writeOutputObject(std::map<faixaEtaria, std::vector<std::string>> &nomesEFaixa, const std::string &arquivoRecebido){
    std::ifstream arquivo(arquivoRecebido);
    std::string linha;
    int idade;

    if (arquivo.is_open()){
        while (std::getline(arquivo, linha)){
            int posicao = linha.find(",");
            if (posicao == std::string::npos) {
                std::cerr << "Linha malformada: " << linha << "\n";
                continue;
            }
            std::string nomeAspas = linha.substr(0, posicao);
            std::string nome = nomeAspas.substr(1, posicao - 2);
            try{
                idade = stoi(linha.substr(posicao + 1));
            }
            catch (const std::invalid_argument &e){
                std::cerr << "Erro ao ler os dados do arquivo\n";
                continue;
            }

            faixaEtaria faixa =  classificarIdade(idade);
            nomesEFaixa[faixa].push_back(nome);
        }
    } else {
        std::cout << "Erro ao abrir arquivo\n";
    }
    arquivo.close();
}

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

void printResult(std::map<faixaEtaria, std::vector<std::string>> &nomesEFaixa){
        for (auto const &item : nomesEFaixa){
        std::string message = converterFaixa(item.first);
        std::cout << message << "\n";
            for (auto const &itemInterno : nomesEFaixa[item.first]){
                std::cout << itemInterno << "\n";
            }
    }
}

std::string converterFaixa(const faixaEtaria &faixa){
    switch (faixa){
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

faixaEtaria classificarIdade(const int &idade){
    if (idade >= 18){
        return ADULTOS;
    } else if (idade >= 13){
        return ADOLESCENTES;
    } else {
        return CRIANCAS;
    }
}