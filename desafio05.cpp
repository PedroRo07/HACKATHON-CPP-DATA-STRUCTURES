#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

bool ehParCorrespondente(char abertura, char fechamento) {
    if (abertura == '(' && fechamento == ')') return true;
    if (abertura == '[' && fechamento == ']') return true;
    if (abertura == '{' && fechamento == '}') return true;
    return false;
}

int main() {
    SetConsoleOutputCP(65001);
    std::string expressao;
    std::vector<char> pilha;
    bool valida = true;

    std::cout << "=== VERIFICADOR DE DELIMITADORES (PILHA) ===\n";
    std::cout << "Digite a expressao: ";
    
    std::getline(std::cin, expressao);

    int tam = expressao.length();

    for (int i = 0; i < tam; i++) {
        char c = expressao[i];

        if (c == '(' || c == '[' || c == '{') {
            pilha.push_back(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (pilha.empty()) {
                valida = false;
                break;
            }

            char topo = pilha.back();
            
            if (ehParCorrespondente(topo, c)) {
                pilha.pop_back();
            } else {
                valida = false;
                break;
            }
        }
    }

    if (!pilha.empty()) {
        valida = false;
    }

    std::cout << "\nExpressao: " << expressao << "\n";
    if (valida) {
        std::cout << "Resultado: EXPRESSÃO VALIDA\n";
    } else {
        std::cout << "Resultado: EXPRESSÃO INVÁLIDA\n";
    }

    return 0;
}