#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

struct cliente {
    string Nome;
    string pedido;
};

int main() {
    SetConsoleOutputCP(65001);
    
    vector<cliente> fila; 
    int opcao;

    do {
        cout << "\n=== BANCADA DO ATENDENTE ===\n";
        cout << "1- Pedir algo (Entrar na fila)\n";
        cout << "2- Atender primeiro cliente\n";
        cout << "3- Lista de clientes e pedidos\n";
        cout << "4- Sair da loja\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            cliente novoCliente;
            cout << "\nNome: ";
            cin.ignore();
            getline(cin, novoCliente.Nome);
            cout << "Pedido: ";
            getline(cin, novoCliente.pedido);
            
            fila.push_back(novoCliente); 
            cout << "\nVoce sera chamado brevemente!\n";
            
        } else if (opcao == 2) {
            if (fila.empty()) {
                cout << "\nNao possui fila alguma!\n";
            } else {
                cout << "\nAtendendo cliente:\n";
                cout << "Nome: " << fila[0].Nome << "\n";
                cout << "Pedido: " << fila[0].pedido << "\n";
                
                fila.erase(fila.begin()); 
            }
            
        } else if (opcao == 3) {
            if (fila.empty()) {
                cout << "\nA fila esta vazia!\n";
            } else {
                cout << "\nClientes na fila:\n";
                for (size_t i = 0; i < fila.size(); i++) {
                    cout << "\nCliente " << i + 1 << "\n";
                    cout << "Nome: " << fila[i].Nome << "\n";
                    cout << "Pedido: " << fila[i].pedido << "\n";
                }
            }
            
        } else if (opcao == 4) {
            cout << "\nSaindo da loja...\n";
        } else {
            cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 4);

    return 0;
}
