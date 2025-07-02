#include "functions.hpp"

int main(){
    std::unique_ptr<Sistema> sistema = std::make_unique<Sistema>();
    try{
        sistema->combate("julio", "pedro", 10);
    } catch(const std::exception& e){
        std::cout << "teste 1\n";
        std::cerr << "Erro: " << e.what() << "\n";
    }
    try{
        sistema->verificarStatusHUD("julio");
    } catch(const std::exception& e){
        std::cout << "teste 2\n";
        std::cerr << "Erro: " << e.what() << "\n";
    }
    try{
        sistema->exibirTodosJogadores();
    } catch(const std::exception& e){
        std::cout << "teste 3\n";
        std::cerr << "Erro: " << e.what() << "\n";
    }
    try{
        sistema->inserirMissao("julio", "missao teste");
    } catch(const std::exception& e){
        std::cout << "teste 4\n";
        std::cerr << "Erro: " << e.what() << "\n";
    }
    try{
        sistema->realizarLogout("julio");
    } catch(const std::exception& e){
        std::cout << "teste 5\n";
        std::cerr << "Erro: " << e.what() << "\n";
    }
    try{
        sistema->verificarMissoes("julio");
    } catch(const std::exception& e){
        std::cout << "teste 6\n";
        std::cerr << "Erro: " << e.what() << "\n";
    }

    try{
        sistema->inserirSistema("combate");
        sistema->inserirSistema("teste");
        sistema->realizarLogin("julio", 100);
        sistema->realizarLogin("pedro", 100);
        sistema->realizarLogin("luan", 100);
        sistema->exibirTodosJogadores();
        sistema->verificarMissoes("julio");
        sistema->combate("julio", "pedro", 50);
        sistema->inserirMissao("julio", "matar goblins");
        sistema->verificarMissoes("julio");
        sistema->realizarLogout("luan");
        sistema->combate("julio", "pedro", 50);
        sistema->exibirTodosJogadores();
        sistema->inserirMissao("julio", "matar goblins 2");
        sistema->verificarMissoes("julio");
        sistema->verificarStatusHUD("julio");
    } catch(const std::exception& e){
        std::cerr << "Erro: " << e.what() << "\n";
    }

    return 0;
}