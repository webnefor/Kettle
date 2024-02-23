
#include "src/config.hpp"

#include <thread>

int main(int argc, char *argv[]) {

    struct opt::options_flag conf = opt::parse(argc, argv);

    CoreServer Kernel(conf);

    while (1) {

        std::thread split[conf.thread];

        for (int i = 0; i < conf.thread; i++) {
            split[i] = std::thread(&CoreServer::start, &Kernel);

            split[i].join();
        }
    }

    return 0;
}
