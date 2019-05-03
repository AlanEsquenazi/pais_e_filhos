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
void pesquisar_aluno(string nome, string aluno){
    ifstream arquivo;
    arquivo.open(nome.c_str());
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
void pesquisar_mae(string nome, string mae){
    ifstream arquivo;
    arquivo.open(nome.c_str());
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
        if(apm[2]==mae){
            cout<<"Aluno: "<<apm[0]<<'\n';
        }
    }
    arquivo.close();
}
void pesquisar_pai(string nome, string pai){
    ifstream arquivo;
    arquivo.open(nome.c_str());
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
        if(apm[1]==pai){
            cout<<"Aluno: "<<apm[0]<<'\n';
        }
    }
    arquivo.close();
}
void pesquisar_aluno_primeiro_nome(string nome, string aluno){
    ifstream arquivo;
    arquivo.open(nome.c_str());
    string line;
    char a_p_n[100];
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
        for(int i=0;i<sizeof(apm[0]);i++){
            if(!(apm[0][i]=='_')){
                a_p_n[i] = apm[0][i];
                //cout<<a_p_n;
            }else{
                break;
            }
        }
        if(a_p_n==aluno){
            cout<<"Aluno: "<<apm[0]<<" Pai: "<<apm[1]<<" Mae: "<<apm[2]<<'\n';
        }
    }
    arquivo.close();
}
void pesquisar_pai_primeiro_nome(string nome, string pai){
    ifstream arquivo;
    arquivo.open(nome.c_str());
    string line;
    char p_p_n[100];
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
        for(int i=0;i<sizeof(apm[1]);i++){
            if(!(apm[1][i]=='_')){
                p_p_n[i] = apm[1][i];
                //cout<<a_p_n;
            }else{
                break;
            }
        }
        if(p_p_n==pai){
            cout<<"Aluno: "<<apm[0]<<" Pai: "<<apm[1]<<" Mae: "<<apm[2]<<'\n';
        }
    }
    arquivo.close();
}

void pesquisar_mae_primeiro_nome(string nome, string mae){
    ifstream arquivo;
    arquivo.open(nome.c_str());
    string line;
    char m_p_n[100];
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
        for(int i=0;i<sizeof(apm[2]);i++){
            if(!(apm[2][i]=='_')){
                m_p_n[i] = apm[2][i];
                //cout<<a_p_n;
            }else{
                break;
            }
        }
        if(m_p_n==mae){
            cout<<"Aluno: "<<apm[0]<<" Pai: "<<apm[1]<<" Mae: "<<apm[2]<<'\n';
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
   if(entrada =="pesquisaraluno"||entrada =="pesquisar aluno"||entrada =="pesquisar_aluno"||entrada =="Pesquisaraluno"||entrada =="P esquisar aluno"||entrada =="Pesquisar Aluno"){
        cin>>aluno;
        pesquisar_aluno("paisefilhos.txt", aluno);
    }else if(entrada=="pesquisarmae"||entrada=="pesquisar mae"||entrada=="Pesquisarmae"||entrada=="Pesquisar mae"||entrada=="Pesquisar Mae"){
        cin>>mae;
        pesquisar_mae("paisefilhos.txt", mae);
    }else if(entrada=="pesquisarpai"||entrada=="pesquisar pai"||entrada=="Pesquisarpai"||entrada=="Pesquisar pai"||entrada=="Pesquisar Pai"){
        cin>>pai;
        pesquisar_pai("paisefilhos.txt", pai);
    }else if(entrada == "pesquisaralunoprimeironome"){
        cin>>aluno;
        pesquisar_aluno_primeiro_nome("paisefilhos.txt",aluno);
    }else if(entrada == "pesquisarpaiprimeironome"){
        cin>>aluno;
        pesquisar_pai_primeiro_nome("paisefilhos.txt",aluno);
    }else if(entrada == "pesquisarmaeprimeironome"){
        cin>>aluno;
        pesquisar_mae_primeiro_nome("paisefilhos.txt",aluno);
    }else{
        cout<<"Comando nao reconhecido; favor digitar pesquisaraluno, pesquisarmae, pesquisarpai, pesquisaralunoprimeironome, pesquisarpaiprimeironome ou pesquisarmaeprimeironome "<<'\n';
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
