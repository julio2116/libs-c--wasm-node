#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "functions.hpp"

FaixaEtaria classificarEnum(const int& idade){
    if(idade >= 60){return IDOSO;}
    else if(idade >= 20){return ADULTO;}
    else if(idade >=15){return ADOLESCENTE;}
    else {return CRIANCA;}
}
std::string faixaEtariaParaTexto(const FaixaEtaria& faixa){
    switch(faixa){
        case CRIANCA: return "Crianca";
        case ADOLESCENTE: return "Adolescente";
        case ADULTO: return "Adulto";
        case IDOSO: return "Idoso";
        default: return "Desconhecido";
    }
}