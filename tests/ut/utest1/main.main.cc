#include <aytest/singleton.hpp>
#include <testlib.h>
#include <iostream>

int main()
{
    auto& ins = aytest::Singleton<AA>::instance();
    std::cout << ins.a_ << std::endl;
    ins.resetA();
    std::cout << ins.a_ << std::endl;
    return 0;
}
