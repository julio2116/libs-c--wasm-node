#include <iostream>
#include <memory>

// class Jogador{
//     public:
//         Jogador(){std::cout << "Jogador criado!" << std::endl;}
//         ~Jogador(){std::cout << "jogador destruido!" << std::endl;}
//         void mostrarVida(){std::cout << 100 << std::endl;}
// };

// int main(){
//     std::unique_ptr<Jogador> player = std::make_unique<Jogador>();
//     player->mostrarVida();

//     return 0;
// }
class Jogador{
    private:
        std::string nome;
        int vida;

    public:
        Jogador(): nome(""), vida(0) {std::cout << "Jogador criado, sem nome ou vida!" << std::endl;}
        Jogador(std::string nomeExt, int vidaExt): nome(nomeExt), vida(vidaExt) {std::cout << "Jogador criado!" << std::endl;}
        ~Jogador(){std::cout << "Jogador destruido!" << std::endl;}
        void exibirStatus(){std::cout << "Nome: " << nome << "\nvida: " << vida << std::endl;}
};

int main(){
    std::shared_ptr<Jogador> player = std::make_shared<Jogador>("Julio", 21);
    std::shared_ptr<Jogador> player2 = std::make_shared<Jogador>("Teste", 35);
    std::shared_ptr<Jogador> referenciaCombate_p1 = player;
    std::shared_ptr<Jogador> referenciaCombate_p2 = player2;
    std::weak_ptr<Jogador> hud_p1 = player;
    std::weak_ptr<Jogador> hud_p2 = player2;

    std::cout << "Jogador 1, esta " << (!hud_p1.expired() ? "vivo!" : "morto!") << std::endl;
    std::cout << "Jogador 2, esta " << (!hud_p2.expired() ? "vivo!" : "morto!") << std::endl;
    
    player.reset();
    referenciaCombate_p1.reset();
    
    std::cout << "Jogador 1, esta " << (!hud_p1.expired() ? "vivo!" : "morto!") << std::endl;
    std::cout << "Jogador 2, esta " << (!hud_p2.expired() ? "vivo!" : "morto!") << std::endl;
    
    hud_p1.reset();
    player2.reset();
    
    std::cout << "Jogador 1, esta " << (!hud_p1.expired() ? "vivo!" : "morto!") << std::endl;
    std::cout << "Jogador 2, esta " << (!hud_p2.expired() ? "vivo!" : "morto!") << std::endl;

    return 0;
}