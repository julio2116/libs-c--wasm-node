#include "functions.hpp"

int main(){
    std::unique_ptr<Sistema> sistema = std::make_unique<Sistema>();
    sistema->inserirSistema("Combate");
    sistema->RealizarLogin("Julio", 100);
    sistema->RealizarLogin("Maria", 100);
    sistema->combate("julio", "maria", 10);

    return 0;
}