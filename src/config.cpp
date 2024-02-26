#include "hcore.hpp"


struct opt::options_flag opt::parse(int argc, char *argv[]) {

    std::vector<std::string> options;
    std::vector<std::string> array_opt { \
            "-m","-v","-p","-t","-h","i"     \
    /*
         * the -m is regime mode: [http or icmp] (default tcp) = 0
         * the -v is for entering target: (target.com) = 1
         * the -p is for entering target's port: (default 80) = 3
         * the -t is indicated the number of thread: (default 2) = 4
         * the -i is for entering time: (default 1s)
         * the -h HELP
    */
    };

    for (int i = 0; i < argc; i++) {
        try {
            if (argv[i] == array_opt.at(0)) {
                set_options.mode        = atoi(argv[i + 1]);
            }
            if (argv[i] == array_opt.at(1)) {
                set_options.host        = get_ip_host(argv[i + 1]);
            }
            if (argv[i] == array_opt.at(2)) {
                set_options.port        = atoi(argv[i + 1]);
            }
            if (argv[i] == array_opt.at(3)) {
                set_options.thread      = atoi(argv[i + 1]);
            }
            if (argv[i] == array_opt.at(4)) {
                set_options.help        = true;
            }
        }
        catch (const std::exception &error)
        {
            opt::show_help();
            std::cerr << error.what() << std::endl;
            exit(-1);
        }
    }
    if (set_options.port < 20) {
        opt::show_help();
        exit(1);
    }

    if (set_options.help) {
        opt::show_help();
        exit(1);
    }

    if (set_options.host == "NONE") {
        opt::show_help();
        exit(1);
    }

    return set_options;
}

void opt::show_help() {
    using std::cout;
    using std::endl;

    cout << "sprey: option requires an argument -h" << endl;
    cout << " usage: sprey"<< endl;
    cout << "\t[-v] target host: example [target.com]" << endl;
    cout << "\t[-p] port host: (default 80)"<< endl;
    cout << "\t[-m] mode http or icmp: (default http)"<< endl;
    cout << "\t[-t] count threads: (default 2)"<< endl;
    cout << endl;

}
