
#include    <iostream>
#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <netdb.h>
#include    <arpa/inet.h>


std::string get_ip_host(char *host) {

    struct hostent *chost;
    struct in_addr **addr;
    unsigned int count;
    char raddr[64];

    if ((chost = gethostbyname(host)) == NULL)
    {
        perror("[-] Gethost: ");
        exit(-1);
    }

    addr = (struct in_addr **) chost->h_addr_list;

    for(count = 0; addr[count] != NULL; count++) {
        strcpy(raddr, inet_ntoa(*addr[count]));
    }

    return (char *)raddr;
}

