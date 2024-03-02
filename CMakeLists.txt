cmake_minimum_required(VERSION 3.27)

project(Kettle)

set(CMAKE_CXX_STANDARD 17)

add_executable(kettle main.cpp
        src/config.cpp
        src/http.cpp
        src/icmp.cpp
        src/receiveip.cpp
        src/config.cpp
)
