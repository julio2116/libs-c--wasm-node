#include <iostream>
#include <queue>
#include <vector>
#include <stack>

int main(){
    std::queue<std::string> inimigos;
    std::vector<std::string> inventario;
    std::stack<std::string> acoes;

    inimigos.push("Dragao");
    inimigos.push("Humano");
    inimigos.push("Elfo");

    inventario.push_back("espada longa");
    inventario.push_back("espada curta");
    inventario.push_back("cajado");

    acoes.push("atacar");
    acoes.push("defender");
    acoes.push("lancar magia");

    std::cout << inimigos.front() << std::endl;
    for(const auto& item : inventario){
        std::cout << item << std::endl;
    }
    while(!acoes.empty()){
        std::cout << acoes.top() << std::endl;
        acoes.pop();
    }

    return 0;
}