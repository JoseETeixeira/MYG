#pragma once

#include <string>
#include <exception>

class FileNotFoundException : public std::exception
{
private:
    std::string msg;

public:
    FileNotFoundException(const std::string& message = "") : msg(message)
    {
    }

    const char * what() const noexcept
    {
        return msg.c_str();
    }
};

class InterruptedException : public std::exception
{
private:
    std::string msg;

public:
    InterruptedException(const std::string& message = "") : msg(message)
    {
    }

    const char * what() const noexcept
    {
        return msg.c_str();
    }
};

class NumberFormatException : public std::exception
{
private:
    std::string msg;

public:
    NumberFormatException(const std::string& message = "") : msg(message)
    {
    }

    const char * what() const noexcept
    {
        return msg.c_str();
    }
};

class IOException : public std::exception
{
private:
    std::string msg;

public:
    IOException(const std::string& message = "") : msg(message)
    {
    }

    const char * what() const noexcept
    {
        return msg.c_str();
    }
};

class StackOverflowError : public std::exception
{
private:
    std::string msg;

public:
    StackOverflowError(const std::string& message = "") : msg(message)
    {
    }

    const char * what() const noexcept
    {
        return msg.c_str();
    }
};

class OutOfMemoryError : public std::exception
{
private:
    std::string msg;

public:
    OutOfMemoryError(const std::string& message = "") : msg(message)
    {
    }

    const char * what() const noexcept
    {
        return msg.c_str();
    }
};
