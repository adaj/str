// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa matatdor.cpp
// Sinais sã eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()



int  main()
{
  // o processo que vai matar

  int meu_pid;
  int pid_vitima;
  int entrada;
  meu_pid = getpid();


    printf( "Eu sou um programa matador de programa meu PID é %d\n", meu_pid );
    printf( "Digite o PID do processo que deve morrer: ");
    scanf( "%d", &pid_vitima);
    printf("\n Vou matar o processo %d \n", pid_vitima);
    while(1){
         printf(" Selecione um op:\n");
         scanf("%d",&entrada);
         if(entrada==1){
             kill(pid_vitima, SIGKILL);
             printf( "\nAgora posso morrer tranquilo.\n");
             exit(0);
        }else if(entrada==2){
            kill(pid_vitima,SIGTSTP);
        }else if(entrada==3){
            kill(pid_vitima,SIGCONT);
        }
    }
}






