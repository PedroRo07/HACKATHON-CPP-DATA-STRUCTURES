#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h>

void limpaTela() {
    system("cls");
}

void pausar() {
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    SetConsoleOutputCP(65001);

    int opcao = -1;
    std::vector<std::string> historico;

    while (opcao != 0) {
        limpaTela();

        std::cout << "1. Registrar ação\n";
        std::cout << "2. Desfazer última ação (Pop)\n";
        std::cout << "3. Mostrar histórico completo\n";
        std::cout << "0. Sair\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                limpaTela();
                int acao = -1;
                std::cout << "--- REGISTRO DE AÇÃO ---\n";
                std::cout << "ESCOLHA UMA DAS OPÇÕES ABAIXO:\n";
                std::cout << "1. Digitou uma palavra\n";
                std::cout << "2. Apagou uma palavra\n";
                std::cout << "3. Alterou uma frase\n";
                std::cout << "4. Inseriu um parágrafo\n";
                std::cout << "Ação: ";
                std::cin >> acao;

                std::string descricaoAcao = "";

                if (acao == 1) {
                    descricaoAcao = "Digitou uma palavra";
                } else if (acao == 2) {
                    descricaoAcao = "Apagou uma palavra";
                } else if (acao == 3) {
                    descricaoAcao = "Alterou uma frase";
                } else if (acao == 4) {
                    descricaoAcao = "Inseriu um parágrafo";
                } else {
                    std::cout << "\nOpção de ação inválida!\n";
                    pausar();
                    break;
                }

                historico.push_back(descricaoAcao);
                std::cout << "\nAção \"" << descricaoAcao << "\" registrada com sucesso!\n";
                pausar();
                break;
            }

            case 2: {
                limpaTela();
                std::cout << "--- DESFAZER ÚLTIMA AÇÃO ---\n";
                if (historico.empty()) {
                    std::cout << "[AVISO] Nenhuma ação para desfazer. O histórico está vazio!\n";
                } else {
                    std::string ultimaAcao = historico.back();
                    
                    historico.pop_back();

                    std::cout << "Ação desfeita com sucesso: \"" << ultimaAcao << "\"\n";
                }
                pausar();
                break;
            }

            case 3: {
                limpaTela();
                std::cout << "--- VISUALIZAÇÃO DO HISTÓRICO COMPLETO ---\n";
                if (historico.empty()) {
                    std::cout << "[AVISO] O histórico está vazio!\n";
                } else {
                    std::cout << "Estado da Pilha (Topo -> Base):\n\n";
                    for (int i = static_cast<int>(historico.size()) - 1; i >= 0; i--) {
                        if (i == static_cast<int>(historico.size()) - 1) {
                            std::cout << " TOPO -> | " << historico[i] << " |\n";
                        } else {
                            std::cout << "         | " << historico[i] << " |\n";
                        }
                        std::cout << "         +------------------------+\n";
                    }
                    std::cout << "         | BASE                   |\n";
                    std::cout << "         +------------------------+\n";
                }
                pausar();
                break;
            }

            case 0:
                limpaTela();
                std::cout << "Saindo do programa...\n";
                break;

            default:
                limpaTela();
                std::cout << "Opção inválida! Tente novamente.\n";
                pausar();
                break;
        }
    }

    return 0;
}