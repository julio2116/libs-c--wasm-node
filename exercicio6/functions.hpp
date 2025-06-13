#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <map>

enum faixaEtaria{
    CRIANCAS,
    ADOLESCENTES,
    ADULTOS
};

void initialFunction(std::vector<std::pair<std::string, int>> &nomesEIdades);
void writeFile(const std::vector<std::pair<std::string, int>> &nomesEIdades, const std::string &arquivoRecebido);
void writeOutputObject(std::map<faixaEtaria, std::vector<std::string>> &nomesEFaixa, const std::string &arquivoRecebido);
void validateNumber(int &number, const std::string &message);
void printResult(std::map<faixaEtaria, std::vector<std::string>> &nomesEFaixa);
std::string converterFaixa(const faixaEtaria &faixa);
faixaEtaria classificarIdade(const int &idade);

class LinhaMalFormadaException : public std::exception {
    std::string message;
public:
    LinhaMalFormadaException(const std::string& linha) {
        message = "Linha malformada detectada: " + linha;
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif