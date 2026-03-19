#include "../../include/core/app.h"
App::App(int port, int num_threads) : server_(port, num_threads) {
}
void App::run() {
    server_.start();
}
void App::stop() {
}
Router& App::router() {
    return server_.getRouter();
}
void App::use(std::function<void(Request&, Response&, std::function<void()>)> middleware) {
    server_.use(middleware);
}
