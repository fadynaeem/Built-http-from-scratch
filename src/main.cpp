#include <functional>
#include "../include/core/App.h"
#include "../include/Request.h"
#include "../include/Response.h"
#include "../include/JSON.h"
#include <iostream>
#include <cstdlib> // for std::getenv
#include <string>
using namespace std;
int main() {
    // Read configuration from environment with sensible defaults
    int port = 8080;
    size_t threads = 4;
    if (const char* p = std::getenv("PORT")) {
        try { port = std::stoi(p); } catch(...) { /* keep default */ }
    }
    if (const char* t = std::getenv("THREADS")) {
        try { threads = std::stoul(t); } catch(...) { /* keep default */ }
    }

    App app(port, threads);
    app.use([](Request& req, Response& res, function<void()> next) {
        cout << req.method << " " << req.path << endl;
        next();
    });
    cout << "Starting server on http://localhost:" << port << " with " << threads << " threads" << endl;
    app.run();
    return 0;
}
