#ifndef ROUTER_HPP
#define ROUTER_HPP
#include <functional>
#include <string>
#include <vector>
#include "Request.h"
#include "Response.h"
using namespace std;
class Router {
public:
    using Handler = function<void(Request&, Response&)>;
    void get(const string& path, Handler handler);
    void post(const string& path, Handler handler);
    void put(const string& path, Handler handler);
    void del(const string& path, Handler handler);
    bool handle(Request& req, Response& res);
private:
    struct Route {
          string method;
          string path;
        Handler handler;
    };
      vector<Route> routes;
};
#endif // ROUTER_HPP
