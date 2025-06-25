#include "functions.hpp"

void percorrer(std::shared_ptr<Node> node){
    if(!node){
        return;
    }

    std::cout << "Decisao: " << node->getDecisao() << std::endl;

    if(node->getSim()){
        std::cout << "  -> Sim\n";
        percorrer(node->getSim());
    }
    
    if(node->getNao()){
        std::cout << "  -> Nao\n";
        percorrer(node->getNao());
    }
}

void listarRequisitos(Missao* missao){
    auto requisitos = missao->getPrerequisitos();

    if(!requisitos.empty()){
        std::cout << "Lista de requisitos para a missao " << missao->getNome() << ":\n";
        for(const auto& requisito : requisitos){
            std::cout << " - " << requisito->getNome() << std::endl;
        }
    } else {
        std::cout << missao->getNome() << " sem prerequisitos!\n";
    }
}