#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string message = "Ola estudante, bem-vindo ao curso de C++!";
    std::cout << message << "\n";
    std::fstream arquivo("dados.txt", std::ios::in | std::ios::out | std::ios::app);

    if(!arquivo.is_open()){
        std::cerr << "erro ao abrir arquivo\n";
        return 1;
    }

    arquivo << message << "\n";

    try{
        arquivo.seekg(4, std::ios::beg);
    }catch(const std::exception &e){
        std::cerr << e.what() << "\n";
    }

    char c;
    while(arquivo.get(c)){
        std::cout << c << "\n";
    }

    return 0;
}