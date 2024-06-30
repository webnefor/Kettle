#include "config.hpp"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <unistd.h>
#include <cstring>
#include <netinet/ip_icmp.h>

unsigned short checksum(void *b, int len) {

    unsigned short *buf = static_cast<unsigned short *>(b);
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int CoreServer::start_icmp() {

    std::string ip_addr = CoreServer::host;

    char *p_addr = new char[ip_addr.length() + 1];
    std::strcpy(p_addr, ip_addr.c_str());
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

//  Create ICMP PACKET ECHO
    struct icmp icmphdr;
    icmphdr.icmp_type = ICMP_ECHO;
    icmphdr.icmp_code = 0;
    icmphdr.icmp_id = htons(getpid() & 0xFFFF);
    icmphdr.icmp_seq = 0;
    icmphdr.icmp_cksum = 0;
    icmphdr.icmp_cksum = checksum(&icmphdr, sizeof(icmphdr));

//  Dest addr
    struct sockaddr_in dest_in;

    memset(&dest_in, 0, sizeof(struct sockaddr_in));

    dest_in.sin_family = AF_INET;

    inet_pton(AF_INET, p_addr, &dest_in.sin_addr);


//    printf("%s", p_addr);

    if (sendto(sockfd, &icmphdr, sizeof(icmphdr), 0, (struct sockaddr *)&dest_in, sizeof(dest_in)) <= 0) {
        perror("sendto");
        return 1;
    }

    printf("\033[032m64 bytes to (%s) [ICMP]\n", CoreServer::host.c_str());
    close(sockfd);

    return 0;
}
