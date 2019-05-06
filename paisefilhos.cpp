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
        for(int i=0;i<line.size();i++){
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
        for(int i=0;i<line.size();i++){
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
        for(int i=0;i<line.size();i++){
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
    while(getline(arquivo, line)){
        string apm[3];
        string a_p_n;
        int conta = 0;
        for(int i=0;i<line.size();i++){
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
        for(int i=0;i<apm[0].size();i++){
            if(!(apm[0][i]==' ')){
                a_p_n += apm[0][i];
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
    while(getline(arquivo, line)){
        string apm[3];
        string p_p_n;
        int conta = 0;
        for(int i=0;i<line.size();i++){
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
        for(int i=0;i<apm[1].size();i++){
            if(!(apm[1][i]==' ')){
                p_p_n += apm[1][i];
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
    while(getline(arquivo, line)){
        string apm[3];
        string m_p_n;
        int conta = 0;
        for(int i=0;i<line.size();i++){
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
        for(int i=0;i<apm[2].size();i++){
            if(!(apm[2][i]==' ')){
                //cout<<"apn[2][i] "<<apm[2][i];
                m_p_n += apm[2][i];
                //cout<<a_p_n;
            }else{
                break;
            }
        }
        cout<<"mpn "<<m_p_n<< " mae eh"<<mae<<'\n';
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
        getline(cin, aluno);
        getline(cin, aluno);
        pesquisar_aluno("paisefilhos.txt", aluno);
    }else if(entrada=="pesquisarmae"||entrada=="pesquisar mae"||entrada=="Pesquisarmae"||entrada=="Pesquisar mae"||entrada=="Pesquisar Mae"){
        getline(cin, mae);
        getline(cin, mae);
        pesquisar_mae("paisefilhos.txt", mae);
    }else if(entrada=="pesquisarpai"||entrada=="pesquisar pai"||entrada=="Pesquisarpai"||entrada=="Pesquisar pai"||entrada=="Pesquisar Pai"){
        getline(cin, pai);
        getline(cin, pai);
        cout<<pai<<'\n';
        pesquisar_pai("paisefilhos.txt", pai);
    }else if(entrada == "pesquisaralunoprimeironome"){
        getline(cin, aluno);
        getline(cin, aluno);
        pesquisar_aluno_primeiro_nome("paisefilhos.txt",aluno);
    }else if(entrada == "pesquisarpaiprimeironome"){
        getline(cin, pai);
        getline(cin, pai);
        pesquisar_pai_primeiro_nome("paisefilhos.txt",pai);
    }else if(entrada == "pesquisarmaeprimeironome"){
        getline(cin, mae);
        getline(cin, mae);
        pesquisar_mae_primeiro_nome("paisefilhos.txt",mae);
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
