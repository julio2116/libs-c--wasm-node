#ifndef FUNCTIONS_HPP
#define FUNCTINOS_HPP
#include <iostream>
#include <string>
#include <vector>

int inserirVisitantes(int visitantes, std::string nome_completo, std::vector<std::string>& todosNomes, int idade, std::vector<int>& todasIdades);
std::string classificarIdade(int idade);

#endif