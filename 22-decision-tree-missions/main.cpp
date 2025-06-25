#include "functions.hpp"

int main(){
    std::string decisao = "Esta perto?";
    std::shared_ptr<Node> comportamento = std::make_shared<Node>(decisao);

    comportamento->setSim("atacar");
    comportamento->setNao("patrulhar");

    comportamento->getSim()->setSim("acertou");
    comportamento->getNao()->setNao("errou");
    comportamento->getSim()->getSim()->setSim("dano causado");

    percorrer(comportamento);

    Missao missaoGoblins("matar goblins");
    Missao missaoDragoes("matar dragoes");
    Missao missaoRecuperarItens("Recupere os itens roubados");
    Missao missaoFugir("Fuja da cadeia em 2 minutos");
    Missao missaoFurtivo("Nao chame a atencao dos guardas durante a fuga");

    missaoGoblins.setRequisito(&missaoDragoes);
    missaoGoblins.setRequisito(&missaoRecuperarItens);
    missaoFugir.setRequisito(&missaoFurtivo);

    listarRequisitos(&missaoGoblins);
    listarRequisitos(&missaoDragoes);
    listarRequisitos(&missaoRecuperarItens);
    listarRequisitos(&missaoFugir);
    listarRequisitos(&missaoFurtivo);

    return 0;
}