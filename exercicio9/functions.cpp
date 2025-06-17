#include "functions.hpp"

void dobrarNiveis(int* vetor, const int& tamanho){
    for(int i = 0; i < tamanho; i++){
        *(vetor + i) = *(vetor + i) * 2;
    }
}
void validarEntradaNumerica(int* numero){
    std::cin >> *numero;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw std::invalid_argument("Falha ao pegar um valor numerico");
    }
    if(*numero <= 0){
        throw std::invalid_argument("Informe um numero maior que 0!");
    }
}
void imprimirValores(int* vetor, const int& tamanho){
    for(int i = 0; i < tamanho; i++){
        std::cout << *(vetor + i) << " ";
    }
}