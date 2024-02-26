
#include "config.hpp"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <unistd.h>
#include <cstring>

int CoreServer::start_http() {

    socklen_t strsize;
    fd_set wset;

    struct sockaddr_in configuration{

    };
    struct timeval tv{
        1,0
    };

    unsigned int sock, result, status, flags,yes =1;

    configuration.sin_addr.s_addr = inet_addr(
            CoreServer::host.c_str()
            );
    configuration.sin_port        = htons(
            CoreServer::port
            );
    configuration.sin_family      = AF_INET;

    strsize = sizeof configuration;

    try {

        sock = socket(AF_INET, SOCK_STREAM, 0);

        result = connect(sock, (struct sockaddr *)&configuration, strsize);

        FD_ZERO(&wset);
        FD_SET(sock, &wset);

        if (result <= 0)
            status = select(sock + 1, NULL, &wset, NULL, &tv);

        if (status <= 0 || status == -1)
        {
            close(sock);
            return -1;
        }

        send(sock, HEADER, strlen(HEADER), 0);

    }
    catch (const std::exception &er)
    {
        std::cerr << er.what() << std::endl;
        close(sock);

        return -1;
    }

    printf("\033[032m64 bytes to (%s):%i\n", CoreServer::host.c_str(),CoreServer::port);

    close(sock);

    return 0;
}
