#include "../include/Server.hpp"
#include <iostream>
#include "../include/PlatformSockets.h"
#include <cstring>
#include <stdexcept>
void Server::setupServer() {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        throw std::runtime_error("Socket failed");
    }
    std::memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (::bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        throw std::runtime_error("Bind failed");
    }
    if (listen(server_fd, 10) < 0) {
        throw std::runtime_error("Listen failed");
    }
}
Router& Server::getRouter() {
    return this->router;
}
