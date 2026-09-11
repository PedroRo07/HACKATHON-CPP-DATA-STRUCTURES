#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    string expressao;

    cout << "========================================\n";
    cout << " CALCULADORA\n";
    cout << "========================================\n";

    cout << "Digite uma expressao:\n";
    getline(cin, expressao);

    stack<int> pilha;

    stringstream entrada(expressao);

    string token;

    bool erro = false;

    while (entrada >> token) {
        if (token != "+" &&
            token != "-" &&
            token != "*" &&
            token != "/") {
            try {

                int numero = stoi(token);
                pilha.push(numero);

            }
            catch (...) {

                cout << "\nERRO: elemento invalido: "
                     << token << endl;

                erro = true;
                break;
            }
        }else {
            if (pilha.size() < 2) {
                cout << "\nERRO."
                     << endl;

                erro = true;
                break;
            }

            int segundo = pilha.top();
            pilha.pop();

            int primeiro = pilha.top();
            pilha.pop();

            int resultado;

            if (token == "+") {
                resultado = primeiro + segundo;
            }else if (token == "-") {
                resultado = primeiro - segundo;
            }else if (token == "*") {
                resultado = primeiro * segundo;
            }else {
                if (segundo == 0) {
                    cout << "\nERRO: divisao por zero."
                         << endl;

                    erro = true;
                    break;
                }
                resultado = primeiro / segundo;
            }
            pilha.push(resultado);
        }
    }

    if (!erro) {

        if (pilha.size() != 1) {
            cout << "\nERRO: expressao invalida."
                 << endl;
        }
        else {
            cout << "\nResultado: "
                 << pilha.top()
                 << endl;
        }
    }

    return 0;
}