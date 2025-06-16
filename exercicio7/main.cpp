#include <iostream>
#include <utility>

int main(){
    int number;
    std::cout << "Insira um numero:\n";
    std::cin >> number;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cerr << "Erro ao colher o numero\n";
        return 1;
    }

    int valorOriginal = number;
    int* p = &number;
    *p *= 2;

    std::cout << "Endereco na memoria:" << &number << "\n";
    std::cout << "Valor original:" << valorOriginal << "\n";
    std::cout << "Valor atual:" << number << "\n";

    return 0;
}