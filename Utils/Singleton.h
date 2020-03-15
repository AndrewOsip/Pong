#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

template <typename T>
class Singleton {
public:
    static T& instance();

private:
    Singleton();

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};

template <typename T>
T& Singleton<T>::instance()
{
    static const std::unique_ptr<T> instance{ new T{} };
    return *instance;
}

#endif // SINGLETON_H
