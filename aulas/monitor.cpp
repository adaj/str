#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main() {

    printf("Monitor de Forks\n");

    while(1){
        system("ps -a");//| grep fork");
        sleep(1);
        system("clear");
    }
    exit(0);
}