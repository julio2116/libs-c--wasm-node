#include "functions.hpp"

int main(){
    int idade;
    std::string nome;
    bool invalidName = true;
    bool invalidIdade = true;

    std::cout << "Insira seu nome:\n";
    while(invalidName){
        std::getline(std::cin, nome);
        if(!std::all_of(nome.begin(), nome.end(), [](char c) { return std::isalpha(c) || std::isspace(c); })){
            std::cerr << "Erro na entrada, insira um apenas letras!\n";
        } else {
            invalidName = false;
        }
    }

    std::cout << "Ola " << nome << ", insira sua idade:\n";

    while(invalidIdade){
        std::cin >> idade;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cerr << "Falha ao pegar a idade!";
            continue;
        }
        if(idade < 1){
            std::cout << "Insira um valor maior que 0!\n";
            continue;
        }
        invalidIdade = false;
    }

    atualizarNome(nome);
    dobrarIdade(&idade);

    std::cout << "Novo nome (substituido): " << nome << "\n";
    std::cout << "Idade dobrada: " << idade << "\n";

    return 0;
}


// int main(){
//     int number;
//     std::cout << "Insira um numero:\n";
//     std::cin >> number;
//     if(std::cin.fail()){
//         std::cin.clear();
//         std::cin.ignore(1000, '\n');
//         std::cerr << "Erro ao colher o numero\n";
//         return 1;
//     }

//     int valorOriginal = number;
//     int* p = &number;
//     *p *= 2;

//     std::cout << "Endereco na memoria:" << &number << "\n";
//     std::cout << "Valor original:" << valorOriginal << "\n";
//     std::cout << "Valor atual:" << number << "\n";

//     return 0;
// }