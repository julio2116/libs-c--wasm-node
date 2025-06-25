#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <memory>
#include <vector>

class Node{
    private:
        std::string decisao;
        std::shared_ptr<Node> sim;
        std::shared_ptr<Node> nao;

    public:
        Node(std::string decisao):decisao(decisao){std::cout << "Decisao: " << decisao << " criada!\n";}
        ~Node(){std::cout << "Decisao: " << decisao << " destruida!\n";}

        std::string getDecisao(){return decisao;}
        std::shared_ptr<Node> getSim(){return sim;}
        std::shared_ptr<Node> getNao(){return nao;}

        void setSim(std::string valorSim){
            sim = std::make_shared<Node>(valorSim);
        }
        void setNao(std::string valorNao){
            nao = std::make_shared<Node>(valorNao);
        }
};

class Missao{
    private:
        std::string nome;
        std::vector<Missao*> prerequisitos;

    public:
        Missao(std::string nome):nome(nome){std::cout << "Missao: " << nome << " criada!\n";}
        ~Missao(){std::cout << "Missao: " << nome << " destruida!\n";}

        void setRequisito(Missao* missao){
            prerequisitos.push_back(missao);
        }

        std::vector<Missao*> getPrerequisitos(){
            return prerequisitos;
        }

        std::string getNome(){
            return nome;
        }
};

void percorrer(std::shared_ptr<Node> node);
void listarRequisitos(Missao* missao);

#endif