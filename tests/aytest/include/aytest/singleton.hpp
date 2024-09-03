#ifndef AYTEST_SINGLETON_HPP_
#define AYTEST_SINGLETON_HPP_

namespace aytest {

template <typename T>
class Singleton : T {
    Singleton(Singleton<T> const &) = delete;
    Singleton<T> & operator=(Singleton<T> const &) = delete;
    Singleton(Singleton<T> &&) = delete;
    Singleton<T> & operator=(Singleton<T> &&) = delete;

    Singleton() = default;

public:
    static T & instance() {
        static Singleton<T> s_instance;
        return s_instance;
    }
};

}

#endif
