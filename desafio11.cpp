#include <iostream>
#include <queue>
#include <string>
#include <windows.h>
using namespace std;

struct Cliente {
    int numero;
    string nome;
    bool prioritario;
};

void mostrarCliente(Cliente cliente) {
    cout << "Cliente "
         << cliente.numero
         << " - "
         << cliente.nome;

    if (cliente.prioritario) {
        cout << " [PRIORITARIO]";
    }
    else {
        cout << " [NORMAL]";
    }
}

int main() {
    SetConsoleOutputCP(65001);
    queue<Cliente> filaNormal;
    queue<Cliente> filaPrioritaria;

    Cliente clientes[15] = {

        {1, "Joao", false},
        {2, "Miguel", true},
        {3, "Gustavo", false},
        {4, "Joana", true},
        {5, "Maria", true},
        {6, "Roberto", false},
        {7, "Carlos", false},
        {8, "Renato", true},
        {9, "Hygor", false},
        {10, "Joaquina", true},
        {11, "Cirilo", false},
        {12, "Gabriel", true},
        {13, "vagalume", false},
        {14, "Alberto", true},
        {15, "Camila", false}
    };

    cout << " Ordem de chamda\n";

    for (int i = 0; i < 15; i++) {

        cout << i + 1 << " - ";

        mostrarCliente(clientes[i]);

        cout << endl;

        if (clientes[i].prioritario) {
            filaPrioritaria.push(clientes[i]);
        }
        else {
            filaNormal.push(clientes[i]);
        }
    }

    cout << "\n\n";
    cout << " Ordem de atendimento\n";

    int ordemAtendimento = 1;

    int prioritariosAtendidos = 0;

    while (!filaNormal.empty() || !filaPrioritaria.empty()) {

        Cliente cliente;

        if (!filaPrioritaria.empty() &&
            (prioritariosAtendidos < 2 || filaNormal.empty())) {

            cliente = filaPrioritaria.front();

            filaPrioritaria.pop();

            prioritariosAtendidos++;
        }
        else {

            cliente = filaNormal.front();

            filaNormal.pop();

            prioritariosAtendidos = 0;
        }

        cout << ordemAtendimento
             << " - ";

        mostrarCliente(cliente);

        cout << endl;

        ordemAtendimento++;
    }

    cout << "Atendimento finalizado\n";

    return 0;
}