#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <vector>

void inserirVisitantes(int visitantes, std::vector<std::string>& todos_nomes, std::vector<int>& todas_idades);
void filtrarVisitantes(int visitantes, std::vector<std::string>& todos_nomes, std::vector<int>& todas_idades);
void classificarIdade(std::vector<int> todas_idades, std::vector<std::string> todos_nomes);
std::string classificar(int idade)

#endif