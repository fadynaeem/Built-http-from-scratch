#include "../include/Router.h"
void Router::get(const std::string& path, Handler handler) {
    routes.push_back({"GET", path, handler});
}
void Router::post(const std::string& path, Handler handler) {
    routes.push_back({"POST", path, handler});
}
void Router::put(const std::string& path, Handler handler) {
    routes.push_back({"PUT", path, handler});
}
void Router::del(const std::string& path, Handler handler) {
    routes.push_back({"DELETE", path, handler});
}
bool Router::handle(Request& req, Response& res) {
    for (const auto& route : routes) {
        if (route.method == req.method) {
            if (route.path == req.path) {
                route.handler(req, res);
                return true;
            }
        }
    }
    return false;
}
