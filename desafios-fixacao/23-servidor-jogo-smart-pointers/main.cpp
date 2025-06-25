#include "functions.hpp"

int main(){
    std::unique_ptr<Servidor> server = std::make_unique<Servidor>();
    server->inserirSistema("combate");
    server->inserirSistema("teste");

    server->conectarJogador("Julio", 100);
    server->conectarJogador("Joao", 100);

    server->exibirTodosStatus();

    server->verificacaoHud("Julio");
    server->verificacaoHud("Joao");
    
    try{
        server->logoutJogador("Joao");
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    try{
        server->verificacaoHud("Julio");
        server->verificacaoHud("Joao");
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }


    return 0;
}