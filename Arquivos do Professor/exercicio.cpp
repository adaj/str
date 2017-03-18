#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int main(){

  pid_t pid;          // definindo um identificador de processo - inteiro longo
  char buf[BUFSIZ];
  printf("Começando o programa fork2 ... \n");
  system("ps");  // tente ps -aux, ps -auf
  sleep(3);
  printf( "\n\nEu sou o Pai %d e vou criar um Filho\n", getpid() );
  pid = fork();

  switch(pid){
    case -1:
      exit(1);
    case 0:
      sleep(5);
      printf( "\t Eu sou o processo %d, filho de %d \n", getpid(), getppid());
      printf( "\t Vou matar meu pai \n");
      snprintf(buf,sizeof(buf),"kill %d",getppid());
      system(buf);
      break;
    default:      // excução do processo Pai
      sleep(3);
      printf(" \nEu sou o processo Pai número de PID =  %d\n", getpid());
      printf(" Fim do Processo Pai\n");
    }
}