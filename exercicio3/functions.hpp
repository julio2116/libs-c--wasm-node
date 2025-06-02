#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

enum FaixaEtaria{
    CRIANCA,
    ADOLESCENTE,
    ADULTO,
    IDOSO
};
FaixaEtaria classificarEnum(const int& idade);
std::string faixaEtariaParaTexto(const FaixaEtaria& faixa);

#endif