#ifndef TESTS_TESTLIB_SINGLETON_HPP_
#define TESTS_TESTLIB_SINGLETON_HPP_

namespace test {

template <typename T>
struct Singleton {
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
