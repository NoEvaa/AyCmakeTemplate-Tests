#pragma once

#include <string>

#include <aytest/singleton.hpp>
#define CHECK(...) test::_check(static_cast<bool>(__VA_ARGS__), #__VA_ARGS__)
struct AA
{
    int a_ = 1;

    void resetA()
{
a_ = 0;
    }
};


namespace test {
void _check(bool, const std::string&);
}
