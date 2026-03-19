#include <functional>
#include "../include/core/app.h"
#include "../include/Request.h"
#include "../include/Response.h"
#include "../include/JSON.h"
#include <iostream>
using namespace std;
int main() {
    App app(8080, 10);
    app.use([](Request& req, Response& res, function<void()> next) {
        cout << req.method << " " << req.path << endl;
        next();
    });
    cout << "Starting server on http://localhost:8080" << endl;
    app.run();
    return 0;
}
