
#include "src/config.hpp"
#include <thread>


int main(int argc, char *argv[]) {

    struct opt::options_flag conf = opt::parse(argc, argv);
    CoreServer Kernel(conf);

    while (true)
    {
        try{

            std::thread * begin_thread = new std::thread [conf.thread];

            for (int i = 0; i < conf.thread;i++) {

                switch (conf.mode) {
                    case HTTP:
                        begin_thread[i] = std::thread(&CoreServer::start_http, &Kernel);
                        break;

                    case ICMP:
                        begin_thread[i] = std::thread(&CoreServer::start_icmp, &Kernel);
                        break;

                    default:
                        opt::show_help();
                        exit(-1);
                }
            }

            for (int k = 0; k < conf.thread;k++)
                begin_thread[k].join();

            delete [] begin_thread ;
        }
        catch (const std::exception &bad) 
            continue;
    }

    return 0;
}
