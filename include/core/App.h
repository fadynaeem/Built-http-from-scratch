#ifndef APP_H
#define APP_H
#include <cstddef>
#include <functional>
#include <vector>
#include "../server.hpp"
class App {
public:
    App(int port, int num_threads);
    void run();
    void stop();
    Router& router();
    void use(function<void(Request&, Response&, function<void()>)> middleware);
private:
    Server server_;
};

#endif // APP_H
