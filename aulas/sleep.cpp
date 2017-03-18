
/////\// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: sleep.c


#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h> // para: sleep()


using std::cout;

//using namespace std;


int main ( ){
   double x = 1;

    //usleep(1000);
    sleep(2);
    printf("O pai do Sleep é: %d\n",getppid());
    return(0);
}

