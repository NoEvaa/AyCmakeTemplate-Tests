#pragma once

#include <string>

#define CHECK(...) test::_check(static_cast<bool>(__VA_ARGS__), #__VA_ARGS__)

namespace test {
void _check(bool, const std::string&);
}
