#include <iostream>
#include <string>
using namespace std;
struct Jogador{
    string nome;
    int pontuacao;
};
int main(){
    Jogador lista[5];
    int n = 5;
    for (int i = 0; i < n; i++){
        cout << "\nDigite o nome do jogador " << i + 1 << ": ";
        cin >> lista[i].nome;
        cout << "Digite a pontuacao: ";
        cin >> lista[i].pontuacao;
    }
    for (int i = 1; i < n; i++) {
        Jogador atual = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j].pontuacao < atual.pontuacao){
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = atual;
        cout << "\nRankeando: " << i + 1 << "° lugar ..." << endl;
        for (int m = 0; m < n; m++);
    }
    cout << "\nPlacar:\n";
    for (int i = 0; i < n; i++){
        cout << i + 1 << "° " << lista[i].nome << " - " << lista[i].pontuacao << " pontos" << endl;
    }
    return 0;
}