#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>

void readOutputFile(const std::vector<std::pair<std::string, int>> &outputFile)
{
    for (const auto &item : outputFile)
    {
        std::cout << item.first << " tem " << item.second << " anos.\n";
    }
}

void writeInputFile(std::vector<std::pair<std::string, int>> &inputFile, const int &usersQtd)
{
    int idade;
    std::string name;
    for (int i = 0; i < usersQtd; i++)
    {
        std::cout << "Insira o nome da pessoa " << i + 1 << "\n";
        std::getline(std::cin >> std::ws, name);
        std::cout << "Qual a idade de " << name << "? \n";
        bool invalid = true;

        while (invalid)
        {
            std::cin >> idade;
            if (std::cin.fail() || idade < 0)
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
        inputFile.push_back(std::make_pair(name, idade));
    }
}

void writeFile(const int &usersQtd, const std::string &data)
{

    std::vector<std::pair<std::string, int>> inputFile;

    std::ofstream archive;

    writeInputFile(inputFile, usersQtd);

    archive.open(data);

    if (archive.is_open())
    {
        for (auto const &item : inputFile)
        {
            archive << "\"" << item.first << "\"," << item.second << "\n";
        }
    }
    archive.close();
}

void readFile(const std::string &data)
{
    std::vector<std::pair<std::string, int>> outputFile;
    std::ifstream archive;
    archive.open(data);
    std::string line;
    std::string::size_type position;

    if (archive.is_open())
    {
        while (std::getline(archive, line))
        {
            if (line.empty())
                continue;
            position = line.find(",");

            std::string nomeAspas = line.substr(0, position);
            std::string nome = nomeAspas.substr(1, position - 2);
            int idade = stoi(line.substr(position + 1));

            outputFile.push_back(std::make_pair(nome, idade));
        }
        readOutputFile(outputFile);
    }
    archive.close();
}
