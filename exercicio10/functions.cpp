#include "functions.hpp"

void validarNumero(int& numero){
    std::cin >> numero;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw std::invalid_argument("Falha ao pegar o numero");
    }
    if(numero <= 0){
        throw std::invalid_argument("Insira um numero maior que 0!");
    }
}

float calcularMedia(int* vetor, const int& tamanho){
    float media;
    int temp = 0;
    for(int i = 0; i < tamanho; i++){
        temp += *(vetor + i);
        media = static_cast<float>(temp) / tamanho;
    }
    return media;
}

void dobrarPontuacoes(int* pontuacoes, const int& tamanho){
    for(int i = 0; i < tamanho; i++){
        *(pontuacoes + i) *= 2;
    }
}

std::string imprimirPontuacoes(int* pontuacoes, const int &tamanho){
    std::string resultado;
    for(int i = 0; i < tamanho; i++){
        resultado += " " + std::to_string(*(pontuacoes + i));
    }
    return resultado;
}