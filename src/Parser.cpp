#include "../include/RequestParser.h"
#include <sstream>
#include <algorithm>

void parseRequest(Request& req, const std::string& rawRequest) {
    using namespace std;
    istringstream stream(rawRequest);
    string line;
    if (!getline(stream, line)) return;
    if (!line.empty() && line.back() == '\r') line.pop_back();
    istringstream lineStream(line);
    lineStream >> req.method >> req.path >> req.version;
    req.headers.clear();
    while (getline(stream, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) break;
        size_t colonPos = line.find(':');
        if (colonPos != string::npos) {
            string name = line.substr(0, colonPos);
            string value = line.substr(colonPos + 1);
            value.erase(0, value.find_first_not_of(" \t\r\n"));
            value.erase(value.find_last_not_of(" \t\r\n") + 1);
            req.headers[name] = value;
        }
    }
    ostringstream bodyStream;
    bodyStream << stream.rdbuf();
    req.body = bodyStream.str();
}
