#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <iomanip>

struct Produto {
    int codigo;
    std::string nome;
    float preco;
    int qtd_estoque;
};

int main() {
    system("cls");
    SetConsoleOutputCP(65001);

    const int tam = 5;
    int opcao;

    Produto lista[tam] = {
        {1, "Arroz", 12.50, 50},
        {2, "Feijão", 7.00, 30},
        {3, "Fubá", 5.45, 25},
        {4, "Água", 2.50, 100},
        {5, "Refrigerante", 4.30, 50},
    };

    std::cout << "Qual o critério de ordenação?\n";
    std::cout << "1. Preço crescente\n";
    std::cout << "2. Nome alfabético\n";
    std::cout << "3. Estoque decrescente\n";
    std::cout << "Critério: ";
    std::cin >> opcao;

    switch (opcao) {

        // INSERTION SORT - PREÇO
        case 1: {
            int comparacoes = 0;

            for (int i = 1; i < tam; i++) {
                Produto chave = lista[i];
                int j = i - 1;

                while (j >= 0) {
                    comparacoes++;
                    if (lista[j].preco > chave.preco) {
                        lista[j + 1] = lista[j];
                        j--;
                    } else {
                        break;
                    }
                }
                lista[j + 1] = chave;
            }
            
            std::cout << std::fixed << std::setprecision(2);

            std::cout << "\nOrdenação por preço crescente:\n";
            for (int i = 0; i < tam; i++) {
                std::cout << i + 1
                          << ". Produto: " << lista[i].nome
                          << " | Preço: R$ " << lista[i].preco
                          << std::endl;
            }
            std::cout << "Número de comparações: "<< comparacoes << std::endl;

            break;
        }

        // SELECTION SORT - NOME
        case 2: {
            int comparacoes = 0;

            for (int i = 0; i < tam - 1; i++) {
                int min_idx = i;

                for (int j = i + 1; j < tam; j++) {
                    comparacoes++;

                    if (lista[j].nome < lista[min_idx].nome) {
                        min_idx = j;
                    }
                }

                if (min_idx != i) {
                    Produto temp = lista[i];
                    lista[i] = lista[min_idx];
                    lista[min_idx] = temp;
                }
            }

            std::cout << "\nOrdenação por nome alfabético:\n";

            for (int i = 0; i < tam; i++) {
                std::cout << i + 1
                          << ". Produto: " << lista[i].nome
                          << " | Preço: R$ " << std::fixed
                          << std::setprecision(2) << lista[i].preco
                          << " | Estoque: " << lista[i].qtd_estoque
                          << std::endl;
            }
            std::cout << "Número de comparações: "<< comparacoes << std::endl;

            break;
        }

        // INSERTION SORT - ESTOQUE
        case 3: {
            int comparacoes = 0;

            for (int i = 1; i < tam; i++) {
                Produto chave = lista[i];
                int j = i - 1;

                while (j >= 0) {
                    comparacoes++;

                    if (lista[j].qtd_estoque < chave.qtd_estoque) {
                        lista[j + 1] = lista[j];
                        j--;
                    } else {
                        break;
                    }
                }

                lista[j + 1] = chave;
            }

            std::cout << "\nOrdenação por estoque decrescente:\n";

            for (int i = 0; i < tam; i++) {
                std::cout << i + 1
                          << ". Produto: " << lista[i].nome
                          << " | Estoque: " << lista[i].qtd_estoque
                          << std::endl;
            }

            std::cout << "Número de comparações: "<< comparacoes << std::endl;

            break;
        }

        default:
            std::cout << "Opção inválida!" << std::endl;
    }
    return 0;
}