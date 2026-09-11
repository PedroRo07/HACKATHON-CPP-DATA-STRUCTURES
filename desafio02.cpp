#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

struct Jogador {
    string nome;
    int pontuacao;
};

int main() {
    SetConsoleOutputCP(65001);
    int n;

    cout << "Digite a quantidade de jogadores no campeonato: ";
    cin >> n;

    if (n <= 0) {
        cout << "A quantidade de jogadores deve ser maior que zero.\n";
        return 1;
    }

    vector<Jogador> lista(n);

    for (int i = 0; i < n; i++) {
        cout << "\nDigite o nome do jogador " << i + 1 << ": ";
        cin >> lista[i].nome;
        cout << "Digite a pontuacao: ";
        cin >> lista[i].pontuacao;
    }

    cout << "\nGerando o ranking final...\n";
    for (int i = 1; i < n; i++) {
        Jogador atual = lista[i];
        int j = i - 1;

        while (j >= 0 && lista[j].pontuacao < atual.pontuacao) {
            lista[j + 1] = lista[j];
            j--;
        }
        
        lista[j + 1] = atual;
    }

    cout << "\nPlacar Final:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "º Lugar: " << lista[i].nome << " - " << lista[i].pontuacao << " pontos\n";
    }
    
    return 0;
}
