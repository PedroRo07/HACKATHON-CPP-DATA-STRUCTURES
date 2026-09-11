#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Encomenda {
    int codigo;
    string bairro;
    int prioridade;
    int horario;
};
bool comparar(Encomenda a, Encomenda b){
    
    if (a.prioridade !=b.prioridade){
        return a.prioridade > b.prioridade;
    }
    
    return a.horario<b.horario;
}
int main(){
    vector<Encomenda>
    encomendas;
    queue<Encomenda>fila;
    
    int quantidade;
    
    cout <<"=== estaçao de entregas===\n";
    
    cout<<"Digite a quantidade de encomendas:";
    cin>>quantidade;
    
        for (int i=0;i<quantidade; i++){
            
            Encomenda e;
            cout<<"\nEncomenda" <<i+1<<endl;
            cout<<"Codigo";
            cin>>e.codigo;
            
            cout<<"Bairro";
            cin>>e.bairro;
            
            cout<<"Prioridade";
            cin>>e.prioridade;
            
            cout<<"Horario de entrega:";
            cin>>e.horario;
            
            encomendas.push_back(e);
        }
        for (Encomenda e : encomendas){
            fila.push(e);
        }
        
        cout <<"\n===ORDEM DE PROCESSAMENTO===\n";
        while (!fila.empty()){
            Encomenda e = fila.front();
            fila.pop();
            
            cout<<"\nCodigo:" << e.codigo;
            cout<<"\nBairro:"<< e.bairro;
            cout<<"\nPrioridade:"<< e.prioridade;
            cout<<"\nHorario de chegada:"<< e.horario;
            cout<<"\n-------------------------------";
        }
        cout<<"\n\nTodas as encoemndas foram processadas!\n";
    return 0;
}