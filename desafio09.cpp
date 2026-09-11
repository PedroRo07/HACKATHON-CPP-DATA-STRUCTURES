#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> voltar;
    stack<string> avancar;

    string paginaAtual = "inicio.com";
    string comando;

    cout << "Navegador Minimalista\n";
    cout << "Pagina atual: " << paginaAtual << endl;

    while (true) {

        cout << "\nComandos: Visitar, Voltar, Avancar, Sair\n";
        cout << "Digite um comando: ";
        cin >> comando;
      
        if (comando == "Visitar") {

            string novaPagina;

            cout << "Digite a pagina: ";
            cin >> novaPagina;

            voltar.push(paginaAtual);
            paginaAtual = novaPagina;

            while (!avancar.empty()) {
                avancar.pop();
            }
        }
        else if (comando == "Voltar") {
            if (voltar.empty()) {
                cout << "Nao existe pagina anterior.\n";
            }
            else {
                avancar.push(paginaAtual);
          
                paginaAtual = voltar.top();
                voltar.pop();
            }
        }
        else if (comando == "Avancar") {

            if (avancar.empty()) {
                cout << "Nao existe pagina para avancar.\n";
            }
            else {
                voltar.push(paginaAtual);
                paginaAtual = avancar.top();
                avancar.pop();
            }
        }
        else if (comando == "Sair") {
            cout << "\nNavegador encerrado.\n";
            break;
        }
        else {
            cout << "Comando invalido!\n";
        }
        cout << "Pagina atual: " << paginaAtual << endl;
    }
    return 0;
}
