#include "functions.hpp"

int main(){
    int niveis;
    std::cout << "Quantos niveis o jogador completou?\n";
    std::cin >> niveis;
    if(std::cin.fail() || niveis < 1){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cerr << "Programa encerrando, informe apenas valores umericos maiores que 0!\n";
        return 1;
    }
    int* vetor = new int[niveis];

    std::cout << "Digite os niveis:\n";

    for(int i = 0; i < niveis; i++){
        int nivel = 0;
        while(nivel <= 0){
            try{
                validarEntradaNumerica(&nivel);
            } catch(const std::exception& e){
                std::cerr << "Entrada invalida, tente novamente. Erro: " << e.what() << "\n";
            }
        }
        *(vetor + i) = nivel;
    }
    std::cout << "Niveis antes de dobrar:\n";
    imprimirValores(vetor, niveis);

    dobrarNiveis(vetor, niveis);

    std::cout << "\nNiveis depois de dobrar:\n";
    imprimirValores(vetor, niveis);

    delete[] vetor;

    return 0;
}