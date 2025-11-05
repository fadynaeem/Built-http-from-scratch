#include "../include/Server.hpp"
#include <iostream>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#endif
#include <cstring>
#include <stdexcept>
#include <iostream>
Server::Server(int port, int num_threads) : port(port), thread_pool(num_threads) {
    setupServer();
}
void Server::addRoute(const string& path, const string& method, void(*handler)(Request&, Response&)) {
    if (method == "GET") {
        router.get(path, handler);
    } else if (method == "POST") {
        router.post(path, handler);
    } else if (method == "PUT") {
        router.put(path, handler);
    } else if (method == "DELETE" || method == "DEL") {
        router.del(path, handler);
    } else {
        router.get(path, handler);
    }
}
void Server::use(function<void(Request&, Response&, function<void()>)> middleware) {
    middlewares.push_back(middleware);
}
void Server::start() {
    while (true) {
        cout << "** server start > while(true) \n";
        socklen_t address_len = sizeof(address);
        cout << "** address: \n";
        int new_socket = accept(server_fd, (struct sockaddr*)&address, &address_len);
        cout << "*** new_socket: " << new_socket << "\n";
        if (new_socket < 0) {
            cerr << "Failed to accept connection" << endl;
            continue;
        }
        thread_pool.enqueue([this, new_socket]() { this->handleRequest(new_socket); });
    }
}
void Server::handleRequest(int new_socket) {
    char buffer[30000] = {0};
#ifdef _WIN32
    int bytesRead = recv(new_socket, buffer, sizeof(buffer) - 1, 0);
#else
    sint bytesRead = read(new_socket, buffer, sizeof(buffer) - 1);
#endif
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        Request request;
        request.parse(buffer);
        Response response;

        processMiddlewares(request, response, 0);

        string response_str = response.toString();
        send(new_socket, response_str.c_str(), response_str.length(), 0);
    }
#ifdef _WIN32
    closesocket(new_socket);
#else
    close(new_socket);
#endif
}
void Server::processMiddlewares(Request& request, Response& response, int index) {
}
// Server networking setup moved to src/ServerNetworking.cpp
void Server::setupServer() {
    // implementation moved to ServerNetworking.cpp
}

Router& Server::getRouter() {
    // implementation moved to ServerNetworking.cpp
    return this->router;
}
