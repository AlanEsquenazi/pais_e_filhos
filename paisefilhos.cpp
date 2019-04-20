#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/*
void adicionar(string nome, string aluno, string pai, string mae){
    fstream arquivo;
    arquivo.open(nome);
    arquivo<<aluno<<":"<<pai<<":"<<mae<<";"<<'\n';
    arquivo.close();
}
*/
void pesquisar(string nome, string aluno){
    ifstream arquivo;
    arquivo.open(nome);
    string line;
    while(getline(arquivo, line)){
        string apm[3];
        int conta = 0;
        for(int i=0;i<sizeof(line);i++){
            if(line[i]==';'){
                break;
            }else{
                if(!(line[i]==':')){
                    apm[conta] +=line[i];
                }else{
                    conta++;
            }
            }
        }
        if(apm[0]==aluno){
            cout<<"Pai: "<<apm[1]<<" Mae: "<<apm[2]<<'\n';
        }
    }
    arquivo.close();
}
void input(string entrada){
    string pai, mae, aluno;
    /*
    if(entrada =="inserir"){
        cin>>aluno>>pai>>mae;
        adicionar("paisefilhos.txt", aluno, pai, mae);
    }else 
    */
   if(entrada =="pesquisar"){
        cin>>aluno;
        pesquisar("paisefilhos.txt", aluno);
    }else{
        cout<<"Comando nao reconhecido";
    }
}
int main(){
    string entrada;
    while(1){
        cin>>entrada;
        if(entrada=="sair"){
            break;
        }else{
            input(entrada);
        }
    }
}