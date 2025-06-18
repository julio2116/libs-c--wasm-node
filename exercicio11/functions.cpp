#include "functions.hpp"

void alocarFases(int **buffer, const int &tamanho){
    *buffer = new int[tamanho];
    preencherFases(*buffer, tamanho);
}

void preencherFases(int *buffer, const int &tamanho){
    for(int i = 0; i < tamanho; i++){
        int numero = 0;
        while(numero <= 0){
            try{
                validarEntrada(numero);
            } catch(const std::exception& e) {
                std::cerr << "Erro: " << e.what() << "\n";
                continue;
            }
        }
        *(buffer + i) = numero;
    }
}

void validarEntrada(int &numero){
    std::cin >> numero;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw std::invalid_argument("insira apenas numeros!\n");
    }
    if(numero < 0){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw std::invalid_argument("insira um numero maior que 0!\n");
    }
}

void dobrarPontuacoes(int* buffer, const int& tamanho){
    for(int i = 0; i < tamanho; i++){
        *(buffer + i) *= 2;
    }
}

void imprimirFases(int* buffer, const int& tamanho){
    for(int i = 0; i < tamanho; i++){
        std::cout << " " << *(buffer + i);
    }
    std::cout << "\n";
}