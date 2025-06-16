#include "functions.hpp"

void dobrarIdade(int* idade){
    *idade *= 2;
}
void formatarNome(std::string* nome){
    for(char& c : *nome){
        c = std::tolower(c);
    }
    (*nome).at(0) = std::toupper((*nome).at(0));
}