
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#define HTTP 0
#define ICMP 1

#define HEADER \
                \
    "GET / HTTP/1.1\r\n"   \
    "Sec-Ch-Ua:" "\"Chromium\";v=" "121," "\"Not A(Brand\";v=" "\"99\"\r\n"\
    "Sec-Ch-Ua-Mobile: ?0\r\n"\
    "Upgrade-Insecure-Requests: 1\r\n"\
    "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.6167.160 Safari/537.36\r\n"\
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7\r\n"\
    "Sec-Fetch-Site: none\r\n"\
    "Sec-Fetch-Mode: navigate\r\n"\
    "Sec-Fetch-User: ?1\r\n"\
    "Sec-Fetch-Dest: document\r\n"\
    "Accept-Encoding: gzip, deflate, br\r\n"\
    "Accept-Language: en-GB,en-US;q=0.9,en;q=0.8\r\n"\
    "Priority: u=0, i\r\n"\
    "Connection: close\r\n"\
    "Content-Length: 0\r\n"\
    "\r\n"

extern unsigned short checksum(void *b, int len);


namespace opt {

    void show_help();

    struct options_flag {
        unsigned int mtime     = 1;
        unsigned int port      = 80;
        unsigned int thread    = 5;
        unsigned int mode      = HTTP;
        std::string host       = "NONE";
        bool help              = false;
    };

    struct options_flag parse(int, char *[]);
}

class CoreServer {

public:

    explicit CoreServer(struct opt::options_flag setter)
            : host(setter.host), port(setter.port),
              thread(setter.thread), active(0b00000001) {};

    virtual ~CoreServer() {};

public:
    int start_http();
    int start_icmp();

private:
    unsigned int ms = 1; // time ms
    unsigned int port;
    unsigned int thread;
    std::string host;
    signed int active;
};
