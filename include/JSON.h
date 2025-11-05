#ifndef JSON_HPP
#define JSON_HPP
#include <string>
#include <vector>
#include <unordered_map>
namespace json {
    class buff {
    public:
        enum Type { Null, Boolean, Number, String };
        buff();
        buff(bool value);
        buff(double value);
        buff(const std::string& value);
        buff(const char* value);
        buff(const buff& other);
        buff& operator=(const buff& other);
        ~buff();
        Type type() const;
        bool isNull() const;
        bool isBoolean() const;
        bool isNumber() const;
        bool isString() const;
        bool asBoolean() const;
        double asNumber() const;
        std::string asString() const;
        std::string stringify(int indent = 0) const;
        static buff parse(const std::string& json);
    private:
        Type m_type;
        union {
            bool m_boolean;
            double m_number;
            std::string* m_string;
        };
        void clear();
        void copyFrom(const buff& other);
    };
}
#endif // JSON_HPP
