
#include "src/config.hpp"
#include <thread>


int main(int argc, char *argv[]) {

    struct opt::options_flag conf = opt::parse(argc, argv);

    CoreServer Kernel(conf);

    while (true) {
        std::vector <std::thread> tsplit;
        try {
            for (int i = 0; i < conf.thread; i++) {
                tsplit.push_back(std::thread(&CoreServer::start, &Kernel));
            }

            for (auto &th: tsplit) {
                th.join();
            }

            tsplit.clear();
        } catch (const std::exception &err) {
            std::cerr << err.what() << std::endl;
            continue;
        }
    }

    return 0;
}
