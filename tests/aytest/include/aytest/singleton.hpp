#ifndef AYTEST_SINGLETON_HPP_
#define AYTEST_SINGLETON_HPP_

namespace test {

template <typename T>
class Singleton : public T {
    Singleton(const Singleton<T>&) = delete;
    Singleton<T>& operator=(const Singleton<T>&) = delete;

public:
    static T & getInstance() {
        static T* s_instance = nullptr;
        if(!s_instance) {
            s_instance = new T;
        }
        return *s_instance;
    }
};

}

#endif
