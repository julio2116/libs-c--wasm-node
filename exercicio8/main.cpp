#include "functions.hpp"

int main(){
    std::string nome;
    int idade;

    std::cout << "Insira seu nome:\n";
    std::getline(std::cin, nome);

    if(!std::all_of(nome.begin(), nome.end(), [](char c){return ::isalpha(c) || ::isspace(c);})){
        std::cerr << "Informe apenas letras e espacos\n";
        return 1;
    }

    formatarNome(&nome);

    std::cout << "Insira sua idade:\n";
    std::cin >> idade;
    if(std::cin.fail() || idade <= 0){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cerr << "Erro na captura do valor de idade, insira um valor maior que 0!";
        return 1;
    }

    dobrarIdade(&idade);

    std::cout << "Nome formatado: " << nome << "\nIdade dobrada: " << idade << "\nEndereco da variavel idade: " << &idade << "\n";

    return 0;
}