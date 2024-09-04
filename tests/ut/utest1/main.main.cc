#include <aytest/singleton.hpp>
#include <aytest/exception.hpp>
#include <stdexcept>
#include <testlib.h>
#include <iostream>

enum class TestMode {
    kCheck = 0,
    kRequire,
};

int main()
{
    try{
        throw std::runtime_error("pp");
    }catch(...){
        std::cout << "ex: " << aytest::getExceptionInfo() << std::endl;
    }
    auto& ins = aytest::Singleton<AA>::instance();
    std::cout << ins.a_ << std::endl;
    ins.resetA();
    std::cout << ins.a_ << std::endl;
    return 0;
}
