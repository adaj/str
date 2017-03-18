#include <iostream>
#include <time.h>
using namespace std;

//Funcao para validar a data
bool valideData(int dia,int mes,int ano){
    if(ano>1970 && mes > 1 && dia > 1){
        return true;
    }else{
        return false;
    }
}

int main(){

    //Variável que armazena o tempo atual
    time_t now;
    //Variável para armazenar a data
    struct tm data;
    //Variáveis que irão receber as entradas do usuário
    int dia,mes, ano,horas,minutos,segundos;



    //Recebendo a entrada do usuário
    cout<<"Dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Ano: ";
    cin>>ano;
    cout<<"Horas: ";
    cin>>horas;
    cout<<"Minutos: ";
    cin>>minutos;
    cout<<"Segundos: ";
    cin>>segundos;
    time(&now);

    //Configurando a entrada na estrutura correta
    data = *localtime(&now);
    data.tm_mday = dia;
    data.tm_mon = mes-1;
    data.tm_year =  ano-1900;
    data.tm_hour = horas;
    data.tm_min = minutos;
    data.tm_sec = segundos;


    //Validando a data fornecida
    if(valideData(dia,mes,ano)){
        //Imprime a data
        cout << "Data Especificada: " <<data.tm_mday << "/" <<data.tm_mon+1 << "/" <<data.tm_year+1900 << "\t" <<data.tm_hour << ":" <<data.tm_min << ":" <<data.tm_sec << "\n";
        //Calcula a diferenca entre tempo atual e o tempo da data fornecida
        time_t seconds = difftime(now,mktime(&data));
        cout<<"Tempo em segundos entre a data Especificada e a data Atual: "<<seconds<<"seg \n";
    }else{
        cout<<"Data Invalida!\n";
    }

}