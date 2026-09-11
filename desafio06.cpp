/*a politica de prioridade utiliza o maior numero de 1 a 3 para priorizar o atendimento do cliente,
ignorando a ordem de chegada a não ser que os pacientes tenham a mesma prioridade. 
*/
#include <iostream>
#include <stack>
using namespace std;
#define MAX 100
struct Paciente{
    string Nome;
    int idade;
    int prioridade;
};
int main(){
    Paciente fila[MAX];
    int quantia = 0;
    int opção;
do{
    cout << "\nFila do hospital\n";
    cout << "1- paciente\n";
    cout << "2- proximo paciente\n";
    cout << "3- lista de pacientes\n";
    cout << "4- sair do hospital\n";
    cout << "escolha uma das opções: \n";
    cin >> opção;
if(opção==1){
    if(quantia >= MAX){
        cout << "fila cheia\n";
    }else{
        cout << "\nNome";
        cin.ignore();
        getline(cin, fila[quantia].Nome);

    cout << "\nidade";
    cin >> fila[quantia].idade;
    cout << "\nprioridade:";
    cin >> fila[quantia].prioridade;
quantia++;
 cout << "\n Paciente esta na fila\n";
   }
}
else if (opção == 2){
    int posição = 0;
    for(int i =1; i< quantia; i++){
        if(fila[i].prioridade > fila[posição].prioridade){
            posição=i;
        }
    }
    for(int i = posição; i< quantia -1; i++){
        fila[i] = fila[i+1];
    }
    quantia--;
}
else if (opção == 3){
cout << "pacientes na fila: \n";
for(int i = 0; i < quantia; i++){
    cout << "\n Paciente" << i+1 << endl;
    cout << "Nome: " << fila[i].Nome << endl;
    cout << "idade: " << fila[i].idade << endl;
    cout << " prioridade: "<< fila[i].prioridade << endl;
    }
}
else if (opção==4){
 cout << "saiu do hospital.\n";
}
else {
    cout << "escolheu errado\n";
}
}
while (opção!=4);
return 0;
}
