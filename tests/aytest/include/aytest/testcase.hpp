#ifndef AYTEST_TESTCASE_HPP_
#define AYTEST_TESTCASE_HPP_

#include <string>
#include <functional>

namespace test {

struct TestCase {
    std::string name_;
    std::function<void(void)> case_;
};

}

#endif
