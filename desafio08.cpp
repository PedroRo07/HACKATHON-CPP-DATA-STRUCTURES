#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Trabalho {
    string usuario;
    int paginas;
    string arquivo;
};


void mostrarF(queue<Trabalho> fila) {
    if (fila.empty()) {
        cout << "\nFila esta vazia.\n";
        return;
    }

    cout << "\nFila de Impressao\n";

    int posicao = 1;

    while (!fila.empty()) {
        Trabalho atual = fila.front();
        fila.pop();

        cout << posicao << ". "
             << "Usuario: " << atual.usuario
             << " | Arquivo: " << atual.arquivo
             << " | Paginas: " << atual.paginas
             << endl;

        posicao++;
    }
}


int pendentes(queue<Trabalho> fila) {
    int total = 0;

    while (!fila.empty()) {
        total += fila.front().paginas;
        fila.pop();
    }

    return total;
}


bool cancelarTrabalho(queue<Trabalho>& fila, string arquivo) {
    queue<Trabalho> auxiliar;
    bool encontrado = false;

    while (!fila.empty()) {
        Trabalho atual = fila.front();
        fila.pop();

        if (atual.arquivo == arquivo && !encontrado) {
            encontrado = true;
        } else {
            auxiliar.push(atual);
        }
    }


    fila = auxiliar;

    return encontrado;
}

int main() {
    queue<Trabalho> fila;

    
    fila.push({"Ana", 10, "relatorio.pdf"});
    fila.push({"Carlos", 5, "trabalho.docx"});
    fila.push({"Maria", 20, "projeto.pdf"});

    mostrarF(fila);

    cout << "\nTotal de paginas pendentes: "
         << pendentes(fila) << endl;

    
    string arquivo;
    cout << "\nDigite o nome do arquivo para cancelar: ";
    cin >> arquivo;

    if (cancelarTrabalho(fila, arquivo)) {
        cout << "Trabalho cancelado com sucesso.\n";
    } else {
        cout << "Trabalho nao encontrado.\n";
    }

    mostrarF(fila);

    cout << "\nTotal de paginas pendentes: "
         << pendentes(fila) << endl;

    return 0;
}
