#ifndef A6_SORECAUADRIAN_1_EXCEPTIONS_H
#define A6_SORECAUADRIAN_1_EXCEPTIONS_H

#include <exception>
#include <string>

class ValueError : public std::exception
{
private:
    std::string message;
public:
    explicit ValueError(const std::string& message);
    std::string get_message();
};

class PermissionError : public std::exception
{
private:
    std::string message;
public:
    explicit PermissionError(const std::string& message);
    std::string get_message();
};

class ValidatorError : public std::exception
{
private:
    std::string message;
public:
    explicit ValidatorError(const std::string& message);
    std::string get_message();
};


#endif //A6_SORECAUADRIAN_1_EXCEPTIONS_H
