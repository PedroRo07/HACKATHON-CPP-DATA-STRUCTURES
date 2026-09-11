#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

struct Tarefa {
    int id;
    string titulo;
    int prioridade;
    int tempo;
};

void mostrarTarefa(Tarefa t) {

    cout << "ID: " << t.id << endl;
    cout << "Titulo: " << t.titulo << endl;
    cout << "Prioridade: " << t.prioridade << endl;
    cout << "Estimativa: " << t.tempo << " minutos" << endl;
    cout << "--------------------------\n";
}

bool ordenarPrioridade(Tarefa a, Tarefa b) {

    if (a.prioridade != b.prioridade) {
        return a.prioridade > b.prioridade;
    }

    return a.tempo < b.tempo;
}

bool ordenarTempo(Tarefa a, Tarefa b) {

    if (a.tempo != b.tempo) {
        return a.tempo < b.tempo;
    }

    return a.prioridade > b.prioridade;
}

int main() {
    SetConsoleOutputCP(65001);
    queue<Tarefa> fila;
    stack<Tarefa> concluidas;
    int opcao;
    int proximoID = 1;

    do {
        cout << "ARENA INTEGRADA\n";

        cout << "1 - Cadastrar tarefa\n";
        cout << "2 - Executar proxima tarefa\n";
        cout << "3 - Desfazer ultima conclusao\n";
        cout << "4 - Mostrar tarefas aguardando\n";
        cout << "5 - Mostrar tarefas concluidas\n";
        cout << "6 - Relatorio por prioridade\n";
        cout << "7 - Relatorio por tempo\n";
        cout << "0 - Sair\n";

        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                Tarefa t;
                t.id = proximoID++;

                cout << "\nDigite o titulo da tarefa: ";
                cin.ignore();
                getline(cin, t.titulo);

                cout << "Digite a prioridade (1 a 5): ";
                cin >> t.prioridade;

                cout << "Digite a estimativa de tempo (minutos): ";
                cin >> t.tempo;
                fila.push(t);

                cout << "\nTarefa cadastrada com sucesso!\n";
                break;
            }

            case 2: {
                if (fila.empty()) {
                    cout << "\nNao existem tarefas aguardando.\n";
                } else {
                    Tarefa t = fila.front();
                    fila.pop();
                    concluidas.push(t);

                    cout << "\nTarefa concluida:\n";
                    mostrarTarefa(t);
                }
                break;
            }

            case 3: {
                if (concluidas.empty()) {
                    cout << "\nNao existe nenhuma conclusao para desfazer.\n";
                } else {
                    Tarefa t = concluidas.top();

                    concluidas.pop();
                    fila.push(t);

                    cout << "\nA ultima tarefa concluida foi desfeita.\n";
                    cout << "Ela voltou para a fila:\n";

                    mostrarTarefa(t);
                }

                break;
            }

            case 4: {
                if (fila.empty()) {
                    cout << "\nA fila esta vazia.\n";
                } else {
                    queue<Tarefa> copia = fila;

                    cout << "\n===== TAREFAS AGUARDANDO =====\n";
                    while (!copia.empty()) {
                        mostrarTarefa(copia.front());
                        copia.pop();
                    }
                }
                break;
            }
            case 5: {
                if (concluidas.empty()) {
                    cout << "\nNao existem tarefas concluidas.\n";
                } else {
                    stack<Tarefa> copia = concluidas;

                    cout << "\n===== TAREFAS CONCLUIDAS =====\n";

                    while (!copia.empty()) {
                        mostrarTarefa(copia.top());
                        copia.pop();
                    }
                }
                break;
            }

            case 6: {
                vector<Tarefa> relatorio;
                
                queue<Tarefa> copiaFila = fila;

                while (!copiaFila.empty()) {
                    relatorio.push_back(copiaFila.front());
                    copiaFila.pop();
                }

                stack<Tarefa> copiaStack = concluidas;

                while (!copiaStack.empty()) {
                    relatorio.push_back(copiaStack.top());
                    copiaStack.pop();
                }
 
                sort(relatorio.begin(), relatorio.end(),
                     ordenarPrioridade);

                cout << "\n===== RELATORIO POR PRIORIDADE =====\n";

                if (relatorio.empty()) {

                    cout << "Nenhuma tarefa cadastrada.\n";

                } else {

                    for (Tarefa t : relatorio) {

                        mostrarTarefa(t);
                    }
                }

                break;
            }

            case 7: {
                vector<Tarefa> relatorio;
                queue<Tarefa> copiaFila = fila;

                while (!copiaFila.empty()) {
                    relatorio.push_back(copiaFila.front());
                    copiaFila.pop();
                }

                stack<Tarefa> copiaStack = concluidas;

                while (!copiaStack.empty()) {
                    relatorio.push_back(copiaStack.top());
                    copiaStack.pop();
                }

                sort(relatorio.begin(), relatorio.end(),
                     ordenarTempo);

                cout << "\n===== RELATORIO POR TEMPO =====\n";

                if (relatorio.empty()) {
                    cout << "Nenhuma tarefa cadastrada.\n";
                } else {
                    for (Tarefa t : relatorio) {
                        mostrarTarefa(t);
                    }
                }
                break;
            }

            case 0:
                cout << "\nPrograma encerrado.\n";
                break;
            default:
                cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}