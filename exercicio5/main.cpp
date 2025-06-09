#include "functions.hpp"

int main()
{
    int usersQtd;
    bool invalid = true;
    std::cout << "Quanto usuarios deseja cadastrar? \n";
    std::string data = "dados.csv";

    while (invalid)
    {
        std::cin >> usersQtd;
        if (std::cin.fail() || usersQtd < 1)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cerr << "Inclua uma entrada valida, apenas numeros positivos \n";
        }
        else
        {
            invalid = false;
        }

    }
    writeFile(usersQtd, data);
    readFile(data);

    return 0;
}