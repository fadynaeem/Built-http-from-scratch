#ifndef REQUEST_HPP
#define REQUEST_HPP
#include <string>
#include <unordered_map>
using namespace std;
class Request {
public:
     string method;
     string path;
     string version;
     unordered_map< string,string> headers;
     string body;
     unordered_map< string,string> queryParams;
     unordered_map< string,string> routeParams;
    void parse(const string& rawRequest);
     string getHeader(const string& name) const;
};
#endif // REQUEST_HPP
