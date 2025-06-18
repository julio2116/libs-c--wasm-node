#include "functions.hpp"

int main(){
    std::cout << "Quantos jogadores participaram?\n";
    int jogadores;
    try{
        validarNumero(jogadores);
    } catch(const std::exception& e){
        std::cerr << "Encerrando execucao da aplicacao: " << e.what() << "\n";
        return 1;
    }
    for(int j = 0; j < jogadores; j++){
        int* vetor = new int[3];
        std::cout << "Digite as pontuacoes do jogador " << j + 1 << ":\n";

        for(int i = 0; i < 3; i++){
            int numero = 0;
            while(numero <= 0){
                try{
                    validarNumero(numero);
                } catch(const std::exception& e){
                    std::cerr << "Erro ao validar pontuacao: " << e.what() << "\n";
                    continue;
                }
            }
            *(vetor + i) = numero;
        }

        std::cout << "Media do jogador " << j + 1 << ": " << calcularMedia(vetor, 3) << "\n";
        dobrarPontuacoes(vetor, 3);
        std::cout << "Pontuacoes dobradas:"<< imprimirPontuacoes(vetor, 3) << "\n";

        delete[] vetor;
    }

    return 0;
}