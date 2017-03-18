#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(){
    system("ps -a");
    printf("Processo sistema:%d\n",getpid());
    system("./../exec/sleep &");
}