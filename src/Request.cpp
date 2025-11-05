#include "../include/Request.h"
#include "../include/RequestParser.h"

void Request::parse(const std::string& rawRequest) {
    parseRequest(*this, rawRequest);
}

std::string Request::getHeader(const std::string& name) const {
    auto it = headers.find(name);
    if (it != headers.end()) {
        return it->second;
    }
    return "";
}
