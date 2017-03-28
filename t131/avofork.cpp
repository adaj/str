//docstrings

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
avo
*/
int main ()
{
  int i;
  pid_t avo, pai1, pai2, filho11, filho12, filho21, filho22;

  sleep(1);
  printf("Sou o processo Avo \n");

  avo = fork();
  switch(avo){
      case -1:
        exit(0);

      //pai1
      case 0:
        //deve dar fork dos filhos de 1 aqui
        filho11 = fork();
        switch(filho11){
            case -1:
              exit(0);
            case 0:
              printf("sou filho11\n");
              while(1);
            default:
              filho12 = fork();
              switch(filho12){
                  case -1:
                    exit(0);
                  case 0:
                    printf("sou filho12\n");
                    while(1);
                  default:
                    printf("sou pai1\n");
                    while(1);
              }

        }

      //avo
      default:

        pai2 = fork();
        switch(pai2){
            case -1:
              exit(0);

            //pai2
            case 0:
              //deve dar fork dos filhos de 2 aqui
              filho21 = fork();
              switch(filho21){
                  case -1:
                    exit(0);
                  case 0:
                    printf("sou filho21\n");
                    while(1);
                  default:
                    filho22 = fork();
                    switch(filho22){
                        case -1:
                          exit(0);
                        case 0:
                          printf("sou filho22\n");
                          while(1);
                        default:
                          printf("sou pai2\n");
                          while(1);
                    }

              }

            default:
              printf("sou avo\n");
              while(1);


        }

  }

}
