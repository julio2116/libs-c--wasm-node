#include <iostream>
#include <vector>

double calcularMedia(const std::vector<int> &notas)
{
    int soma = 0;
    if (notas.size() < 1)
    {
        std::cout << "E necessario ao menos uma nota para executar o programa \n";
        return 0.0;
    }
    else
    {
        for (const auto &nota : notas)
        {
            soma += nota;
        }
        return soma / notas.size();
    }
}

int main()
{
    std::vector<int> notas;
    bool incluir = true;
    int nota;
    double media;

    while (incluir)
    {
        std::cout << "Digite uma nova nota (ou qualquer letra para finalizar): \n";
        std::cin >> nota;
        if (std::cin.fail())
        {
            incluir = false;
        }
        else
        {
            notas.push_back(nota);
        }
    }

    media = calcularMedia(notas);

    if (media >= 80.0)
    {
        std::cout << "Sua media foi de: " << media << " Excelente desempenho!\n";
    }
    else if (media >= 50.0)
    {
        std::cout << "Sua media foi de: " << media << " Bom, mas da para melhorar!\n";
    }
    else if (media > 0.0)
    {
        std::cout << "Sua media foi de: " << media << " Estude os padroes dos inimigos!\n";
    }

    return 0;
}