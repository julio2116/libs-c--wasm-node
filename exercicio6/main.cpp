#include <iostream>

int main(){
    int usersQtd;
    bool next = true;
    std::cout << "Quantos usuarios deseja cadastrar?\n";
    while (next){
        std::cin >> usersQtd;
        if (std::cin.fail() || usersQtd < 1){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Insira um numero valido\n";
        } else {
            next = false;
        }
    }
    return 0;
}