cmake_minimum_required(VERSION 3.10)
project(SimplifiedBlockchain)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

include_directories(include)
add_executable(blockchain src/main.cpp src/Block.cpp src/Blockchain.cpp)

target_link_libraries(blockchain OpenSSL::SSL OpenSSL::Crypto)