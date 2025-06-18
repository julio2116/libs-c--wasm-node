#include <iostream>
#include <fstream>

int main(){
    std::ifstream arquivo("mensagem.txt");
    
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir arquivo!\n";
        return 1;
    }
    
    arquivo.seekg(7, std::ios::beg);
    char c;
    for(int i = 0; i < 20; i++){
        arquivo.get(c);
        std::cout << c;
    }

    arquivo.close();

    return 0;
}