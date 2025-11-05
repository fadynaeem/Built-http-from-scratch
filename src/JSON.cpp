#include "../include/JSON.h"
#include <sstream>
using namespace json;
 buff:: buff() : m_type(Null) {}
 buff:: buff(bool value) : m_type(Boolean) { m_boolean = value; }
 buff:: buff(double value) : m_type(Number) { m_number = value; }
 buff:: buff(const std::string& value) : m_type(String) { m_string = new std::string(value); }
 buff:: buff(const char* value) : m_type(String) { m_string = new std::string(value); }
 buff:: buff(const  buff& other) {
    copyFrom(other);
}
 buff&  buff::operator=(const  buff& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}
 buff::~ buff() {
    clear();
}
void  buff::clear() {
    if (m_type == String) {
        delete m_string;
        m_string = nullptr;
    }
    m_type = Null;
}
void  buff::copyFrom(const  buff& other) {
    m_type = other.m_type;
    switch (other.m_type) {
        case Null: break;
        case Boolean: m_boolean = other.m_boolean; break;
        case Number: m_number = other.m_number; break;
        case String: m_string = new std::string(*other.m_string); break;
    }
}

 buff::Type  buff::type() const { return m_type; }
bool  buff::isNull() const { return m_type == Null; }
bool  buff::isBoolean() const { return m_type == Boolean; }
bool  buff::isNumber() const { return m_type == Number; }
bool  buff::isString() const { return m_type == String; }

bool  buff::asBoolean() const { return m_boolean; }
double  buff::asNumber() const { return m_number; }
std::string  buff::asString() const { return (m_string ? *m_string : std::string()); }

std::string  buff::stringify(int /*indent*/) const {
    switch (m_type) {
        case Null: return "null";
        case Boolean: return m_boolean ? "true" : "false";
        case Number: {
            std::ostringstream oss;
            oss << m_number;
            return oss.str();
        }
        case String: return "\"" + *m_string + "\"";
    }
    return "";
}
 buff  buff::parse(const std::string& json) {
    return  buff(json);
}
