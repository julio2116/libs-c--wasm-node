#include "functions.hpp"

int main(){
    std::unique_ptr<Sistema> sistema = std::make_unique<Sistema>();
    sistema->inserirSistema("Combate");
    sistema->RealizarLogin("Julio", 100);
    sistema->RealizarLogin("Maria", 100);
    sistema->RealizarLogin("Pedro", 100);

    try{
        sistema->verificarStatusJogadores();
    }catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << "\n";
    }

    try{
        sistema->inserirMissao("Julio", "matar goblins");
        sistema->verificarMissoes("Julio");
        sistema->inserirMissao("Julio", "matar dragoes");
        sistema->verificarMissoes("Julio");
    }catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << "\n";
    }
    
    for(int i = 0; i < 10; i++){
        if(i == 5){
            try{
                sistema->realizarLogout("Pedro");
            } catch(const std::exception& e){
                std::cerr << "Error: " << e.what() << "\n";
            }
        }
        try{
            sistema->combate("Julio", "Maria", 10);
        }catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    sistema->verificarStatusJogadores();

    return 0;
}