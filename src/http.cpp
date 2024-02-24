
#include "config.hpp"


#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <fcntl.h>


int CoreServer::start() {

    char buff[1024];
    unsigned int sock, result, status, flags;
    socklen_t strsize;
    struct sockaddr_in configuration;

    configuration.sin_addr.s_addr = inet_addr(
            CoreServer::host.c_str()
            );
    configuration.sin_port        = htons(
            CoreServer::port
            );
    configuration.sin_family      = AF_INET;

    strsize = sizeof configuration;

    struct timeval tv;

    tv.tv_sec = 2;
    tv.tv_usec = 0;

    fd_set wset;

    try {

        sock = socket(AF_INET, SOCK_STREAM, 0);

        if (fcntl(sock, F_SETFL, O_NONBLOCK | O_ASYNC) < 0) {
            perror("");
        }

        FD_ZERO(&wset);

        FD_SET(sock, &wset);

        status = connect(sock, (struct sockaddr *) &configuration, strsize);

        if (errno != EINPROGRESS && errno != EWOULDBLOCK) {
            perror("[\033[033m]\n");
//            close(sock);
        }

        if (status < 0)
            result = select(sock + 1, NULL, &wset, NULL, &tv);
            send(sock, HEADER, strlen(HEADER), 0);

        if (result == 0)
        {
            printf("\033[031m(%s) <501> [-]\n",CoreServer::host.c_str());
//            close(sock);
        }

        else if (result < 0) {
            perror("[\033[033m]\n");
//            close(sock);
//            exit(1);
        }

        printf("\033[032m(%s) <200> [+]\n",CoreServer::host.c_str());

        close(sock);


    } catch (const std::exception &er) {
        std::cerr << er.what() << std::endl;
    }


    return 0;
}
