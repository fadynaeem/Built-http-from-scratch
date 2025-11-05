#include "../include/Response.h"
#include <sstream>
Response::Response() : statusCode(200), statusText("OK") {
    setHeader("Server", "C++ HTTP Server");
    setContentType("text/plain");
}
void Response::setHeader(const std::string& name, const std::string& value) {
    headers[name] = value;
}
void Response::setContentType(const std::string& type) {
    setHeader("Content-Type", type);
}
void Response::setStatus(int code, const std::string& text) {
    statusCode = code;
    statusText = text;
}
std::string Response::toString() const {
    std::stringstream response;
    response << "HTTP/1.1 " << statusCode << " " << statusText << "\r\n";

    for (const auto& header : headers) {
        response << header.first << ": " << header.second << "\r\n";
    }
    response << "Content-Length: " << body.size() << "\r\n";
    response << "\r\n";
    response << body;
    return response.str();
}
void Response::json(const json::buff& data) {
    setContentType("application/json");
    body = data.stringify();
}
void Response::text(const std::string& text) {
    setContentType("text/plain");
    body = text;
}
void Response::html(const std::string& html) {
    setContentType("text/html");
    body = html;
}
