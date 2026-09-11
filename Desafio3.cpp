/*a fila foi utiliza de um jeito simples apenas precisando da ordem de chegada, diferenta da fila da questão 6 
que priorizava a ordem de chegada e a prioridade de atendimento*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define max 40
struct cliente {
    string Nome;
    string pedido;
};
int main() {
    cliente fila[max];
    int quantia = 0;
    int opção;
do {
    cout << "\nbancada do atendente\n";
    cout << "1- pedir algo\n";
    cout << "2- atender primeiro cliente\n";
    cout << "3- lista de clientes e pedidos\n";
    cout << "4- sair da loja\n";
    cin >> opção;
if (opção == 1) {
    if (quantia >= max) {
        cout << "\nmuitos pedidos ja sendo feitos";
    } else {
     cout << "\nNome: ";
        cin.ignore();
        getline(cin, fila[quantia].Nome);
    cout << "\npedido: ";
    getline(cin, fila[quantia].pedido);
    quantia++;
    cout << "\nVoce sera chamado brevemente";
    }
}else if (opção == 2) {
    if (quantia == 0) {
    cout << "\nnão possui fila alguma";
    } else {
        cout << "\nAtendendo cliente:";
        cout << "\nNome: " << fila[0].Nome;
        cout << "\nPedido: " << fila[0].pedido;
    for (int i = 0; i < quantia - 1; i++) {
        fila[i] = fila[i + 1];
    }
    quantia--;
    }
}
else if (opção == 3) {
    if (quantia == 0) {
     cout << "\nA fila esta vazia!";
    } else {
     cout << "\nClientes na fila:\n";
     for (int i = 0; i < quantia; i++) {
         cout << "\nCliente " << i + 1 << endl;
         cout << "Nome: " << fila[i].Nome << endl;
         cout << "Pedido: " << fila[i].pedido << endl;
     }
    }
    }
else if (opção == 4) {
    cout << "\nSaindo da loja";
    }else{
     cout << "\nOpcao invalida";
    }
}while (opção != 4);
return 0;
}