/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Chamada {
    int id;
    string nome;
};

int main() {

    queue<Chamada> fila;
    stack<string> pilha;

    int opcao;
    int proximoID = 1;

    do {

        cout << "\n===== SIMULADOR DE CHAMADAS =====\n";
        cout << "1 - Receber chamada\n";
        cout << "2 - Atender chamada\n";
        cout << "3 - Registrar acao\n";
        cout << "4 - Desfazer ultima acao\n";
        cout << "5 - Encerrar atendimento\n";
        cout << "6 - Mostrar fila\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {

            case 1: {
                Chamada chamada; 

                chamada.id = proximoID++;

                cout << "Nome do cliente: ";
                cin >> chamada.nome;

                fila.push(chamada);

                cout << "Chamada recebida com sucesso!\n";

                break;
            }

            case 2: {

                if (fila.empty()) {
                    cout << "Nao existem chamadas na fila.\n";
                }
                else {

                    Chamada chamada = fila.front();
                    fila.pop();

                    cout << "\nAtendendo chamada...\n";
                    cout << "ID: " << chamada.id << endl;
                    cout << "Cliente: " << chamada.nome << endl;
                }

                break;
            }

            case 3: {

                string acao;

                cout << "Digite a acao realizada: ";
                cin.ignore();
                getline(cin, acao);

                pilha.push(acao);

                cout << "Acao registrada!\n";

                break;
            }
            case 4: {

                if (pilha.empty()) {

                    cout << "Nao existem acoes para desfazer.\n";

                } else {

                    cout << "Desfazendo: " << pilha.top() << endl;

                    pilha.pop();

                    cout << "Acao desfeita!\n";
                }

                break;
            }

            case 5: {

                cout << "\nAtendimento encerrado.\n";

                while (!pilha.empty()) {
                    pilha.pop();
                }

                break;
            }

            case 6: {

                if (fila.empty()) {

                    cout << "A fila esta vazia.\n";

                } else {

                    queue<Chamada> copia = fila;

                    cout << "\n===== FILA DE CHAMADAS =====\n";

                    while (!copia.empty()) {

                        cout << "ID: " << copia.front().id
                             << " | Cliente: "
                             << copia.front().nome << endl;

                        copia.pop();
                    }
                }

                break;
            }

            case 0:
                cout << "Programa encerrado.\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}

