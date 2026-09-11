#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int comparacoes = 0;

    cout << "PODIO RELAMPAGO\n";
    cout << "Quantidade de competidores: ";
    cin >> n;

    if (n <= 0) {
        cout << "Quantidade invalida!\n";
        return 0;
    }

    vector<double> tempos(n);


    for (int i = 0; i < n; i++) {
        cout << "Tempo do competidor " << i + 1 << " (segundos): ";
        cin >> tempos[i];
    }

    
    cout << "\nAntes da ordenacao:\n";

    for (int i = 0; i < n; i++) {
        cout << tempos[i] << "s ";
    }

    cout << endl;


    for (int i = 0; i < n - 1; i++) {

        int menor = i;

        for (int j = i + 1; j < n; j++) {

            comparacoes++;

            if (tempos[j] < tempos[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            double temp = tempos[i];
            tempos[i] = tempos[menor];
            tempos[menor] = temp;
        }
    }

    
    cout << "\nDepois da ordenacao:\n";

    for (int i = 0; i < n; i++) {
        cout << tempos[i] << "s ";
    }

    cout << "\n\nQuantidade de comparacoes: "
         << comparacoes << endl;

    return 0;
}
