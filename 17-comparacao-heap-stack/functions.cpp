#include "functions.hpp"

void comparaFuncoes(std::function<void()> funcao){
    auto inicio = std::chrono::high_resolution_clock::now();

    funcao();

    auto fim = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duracao = fim - inicio;

    std::cout << "Tempo de execucao: " << duracao.count() << "ms" << std::endl;
}

void somaValoresHeap(){
    int tamanho = 100000;
    int* numeros = new int[tamanho];
    long long soma = 0;
    for(int i = 0; i < tamanho; i++){
        numeros[i] = i + 1;
    }
    for(int i = 0; i < tamanho; i++){
        soma += numeros[i];
    }
    std::cout << "heap: " << soma << std::endl;
    delete[] numeros;
}

void somaValoresHeapGecInt(){
    int tamanho = 100000;
    std::vector<int> numeros;
    numeros.resize(tamanho);
    long long soma = 0;
    for(int i = 0; i < tamanho; i++){
        numeros[i] = i + 1;
    }
    for(int i = 0; i < tamanho; i++){
        soma += numeros[i];
    }
    std::cout << "stack: " << soma << std::endl;
}

void somaValoresStackReal() {
    const long long tamanho = 100000;
    int numeros[tamanho];
    long long soma = 0;

    for (int i = 0; i < tamanho; ++i) {
        numeros[i] = i + 1;
    }
    for (int i = 0; i < tamanho; ++i) {
        soma += numeros[i];
    }

    std::cout << "stack real: " << soma << std::endl;
}
