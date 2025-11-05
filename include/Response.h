#ifndef RESPONSE_HPP
#define RESPONSE_HPP
#include <string>
#include <unordered_map>
#include "JSON.h"
using namespace  std;
class Response {
public:
    int statusCode;
      string statusText;
      unordered_map< string,string> headers;
      string body;
    Response();
    void setHeader(const string& name,const string& value);
    void setContentType(const string& type);
    void setStatus(int code, const string& text = "");
      string toString() const;
    void json(const json::buff& data);
    void text(const string& text);
    void html(const string& html);
};
#endif // RESPONSE_HPP
