//
//  cliente4.cpp
//
//
//  Created by Affonso on 25/04/16.
//
//

// programa cliente4.cp --> ler um vetor de caracter

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

float vetor_ch[3];

void *getPot(void *threadid)
{

    while(1)
    {

        int sockfd;
        int len;
        struct sockaddr_in address;
        int result;

        sockfd  = socket(AF_INET, SOCK_STREAM,0);
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr("192.168.0.187");
        address.sin_port = 9731;
        len = sizeof(address);
        result = connect(sockfd, (struct sockaddr *) &address, len);


        sleep(1);
        recv(sockfd, vetor_ch,sizeof(vetor_ch),0);
        printf("%f\n", vetor_ch[0]);

        close(sockfd);

    }
}

void *sendPot(void *threadid)
{

    while(1)
    {

        int sockfd1;
        int len1;
        struct sockaddr_in address1;
        int result1;

        sockfd1  = socket(AF_INET, SOCK_STREAM,0);
        address1.sin_family = AF_INET;
        address1.sin_addr.s_addr = inet_addr("192.168.0.187");
        address1.sin_port = 9735;
        len1 = sizeof(address1);
        result1 = connect(sockfd1, (struct sockaddr *) &address1, len1);


        sleep(1);
        send(sockfd1,  vetor_ch,sizeof(vetor_ch),0);


        close(sockfd1);
    }
}


int main( )
{
    pthread_t thread1, thread2;
    int i1,i2;

    i1 = pthread_create( &thread1, NULL, sendPot, (void*) 1);
    i2 = pthread_create( &thread2, NULL, getPot, (void*) 2);

    while(1){
        int a = 0;
    }

    exit(0);
}

