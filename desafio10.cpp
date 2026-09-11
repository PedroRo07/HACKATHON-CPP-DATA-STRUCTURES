#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cstdlib>
#include <windows.h>

void pausar() {
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.ignore();
    std::cin.get();
}

std::vector<int> gerarVetor(int tamanho) {
    std::vector<int> lista(tamanho);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100000);
    
    for(int i = 0; i < tamanho; i++) {
        lista[i] = dis(gen);
    }
    return lista;
}

void selectionSort(std::vector<int> lista) {
    int n = lista.size();
    int trocas = 0, comparacoes = 0;
    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (lista[j] < lista[menor]) {
                menor = j;
            }
        }
        
        if (menor != i) {
            std::swap(lista[i], lista[menor]);
            trocas++;
        }
    }
    
    auto fim = std::chrono::high_resolution_clock::now();
    std::cout << "\n[SELECTION SORT concluído em vetor de " << n << " elementos]\n" 
              << "Tempo de execução: " << std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio).count() << "ms\n"
              << "Comparações: " << comparacoes << " | Trocas: " << trocas << "\n";
}

void insertionSort(std::vector<int> lista) {
    int n = lista.size();
    int movimentacoes = 0, comparacoes = 0;
    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < n; i++) {
        int atual = lista[i];
        int j = i - 1;
        comparacoes++; 
        
        while (j >= 0 && lista[j] > atual) {
            lista[j + 1] = lista[j];
            j--;
            movimentacoes++;
            if (j >= 0) comparacoes++; 
        }
        lista[j + 1] = atual;
    }

    auto fim = std::chrono::high_resolution_clock::now();
    std::cout << "\n[INSERTION SORT concluído em vetor de " << n << " elementos]\n" 
              << "Tempo de execução: " << std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio).count() << "ms\n"
              << "Comparações: " << comparacoes << " | Movimentações: " << movimentacoes << "\n";
}

void menuOrdenacao(int tamanho) {
    int opcao = -1;
    
    while (opcao != 0) {
        system("cls");
        std::cout << "=======================================\n";
        std::cout << "  CONJUNTO GERADO: " << tamanho << " ELEMENTOS\n";
        std::cout << "=======================================\n";
        std::cout << "1. Executar Selection Sort\n";
        std::cout << "2. Executar Insertion Sort\n";
        std::cout << "0. Voltar ao Menu Principal\n";
        std::cout << "---------------------------------------\n";
        std::cout << "Escolha um algoritmo: ";
        std::cin >> opcao;

        if (opcao == 1 || opcao == 2) {
            std::vector<int> dados = gerarVetor(tamanho);
            
            if (opcao == 1) {
                selectionSort(dados);
            } else {
                insertionSort(dados);
            }
            pausar();
        } else if (opcao != 0) {
            std::cout << "\nOpção inválida!\n";
            pausar();
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);
    int opcaoPrincipal = -1;

    while (opcaoPrincipal != 0) { 
        system("cls");
        std::cout << "=======================================\n";
        std::cout << "   DESAFIO DOS ALGORITMOS - HACKATHON  \n";
        std::cout << "=======================================\n";
        std::cout << "Selecione a quantidade de números a gerar:\n";
        std::cout << "1. 100 números\n";
        std::cout << "2. 1.000 números\n";
        std::cout << "3. 10.000 números\n";
        std::cout << "0. Sair do simulador\n";
        std::cout << "---------------------------------------\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcaoPrincipal;

        switch (opcaoPrincipal) { 
            case 1:
                menuOrdenacao(100);
                break;
            case 2:
                menuOrdenacao(1000);
                break;
            case 3:
                menuOrdenacao(10000);
                break;
            case 0:
                std::cout << "\nEncerrando o simulador...\n";
                break;
            default:
                std::cout << "\nOpção inválida! Tente novamente.\n";
                pausar();
                break;
        }
    }
    return 0;
}