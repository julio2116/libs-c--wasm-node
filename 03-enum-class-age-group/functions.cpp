#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "functions.hpp"

FaixaEtaria classificarEnum(const int& idade){
    if(idade >= 60){return FaixaEtaria::IDOSO;}
    else if(idade >= 20){return FaixaEtaria::ADULTO;}
    else if(idade >= 15){return FaixaEtaria::ADOLESCENTE;}
    else {return FaixaEtaria::CRIANCA;}
}
std::string faixaEtariaParaTexto(const FaixaEtaria& faixa){
    switch(faixa){
        case FaixaEtaria::CRIANCA: return "Crianca";
        case FaixaEtaria::ADOLESCENTE: return "Adolescente";
        case FaixaEtaria::ADULTO: return "Adulto";
        case FaixaEtaria::IDOSO: return "Idoso";
        default: return "Desconhecido";
    }
}