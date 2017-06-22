//
//  servidor4.cpp
//
//
//  Created by Affonso on 25/04/16.
//
//

// programa servidor4.cpp - Servidor que l� e escreve em um vetor de caracter

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

int main( )
{
    int server_sockfd, client_sockfd;
    size_t server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    unlink("server_socket");  // remocao de socket antigo
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);  // cria um novo socket

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.0.187");
    server_address.sin_port = 9731;

    //strcpy(server_address.sun_path, "server_socket");

    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *) &server_address, server_len);

    listen(server_sockfd, 5);
    while(1) {
        float vetor_ch[3];

        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, (socklen_t *) &client_len);


        vetor_ch[0] = RandomFloat(0.0,2.0);
        vetor_ch[1] = RandomFloat(0.0,2.0);
        vetor_ch[2] = RandomFloat(0.0,2.0);


        write(client_sockfd, vetor_ch, sizeof(vetor_ch));
        close(client_sockfd);
    }
}
