#include <iostream>
#include <vector>

int main(){
    std::vector<int> notas;
    int soma;
    bool incluir = true;
    int nota;
    int media;

    while(incluir){
        std::cout << "inclua uma nova nota ou digite qualquer tecla diferente de um numero! \n";
        std::cin >> nota;
        if(std::cin.fail()){
            incluir = false;
        } else {
            notas.push_back(nota);
        }
    }

    if(notas.size() < 1){
        std::cout << "E necessario ao menos uma nota para executar o programa \n";
    } else {
        for(const auto &nota : notas){
            soma += nota;
        }
        media = soma / notas.size();
        if(media >= 80){
            std::cout << "Sua media foi de: " << media << " Excelente desempenho!\n";
        } else if(media >= 50){
            std::cout << "Sua media foi de: " << media << " Bom, mas da para melhorar!\n";
        } else {
            std::cout << "Sua media foi de: " << media << " Estude os padroes dos inimigos!\n";
        }
    }

    return 0;
}