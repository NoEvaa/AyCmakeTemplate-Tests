#ifndef AYTEST_TESTCASE_HPP_
#define AYTEST_TESTCASE_HPP_

#include <string>
#include <functional>

namespace aytest {

struct TestCase {
    std::string name_;

    std::function<void(TestCase *)> fn_case_;

    std::size_t cnt_exec_ = 0;
    std::size_t cnt_pass_ = 0;
    std::size_t cnt_fail_ = 0;

    bool run() {
        reset();
        if (!fn_case_) {
            return false;
        }
        try {
            fn_case_(this);
        } catch(...) {
            return false;
        }
        return true;
    }

    void reset() {
        cnt_exec_ = 0;
        cnt_pass_ = 0;
        cnt_fail_ = 0; 
    }
};

}

template <>
struct std::hash<aytest::TestCase> {
    size_t operator()(aytest::TestCase const & _tc) const {
        return std::hash<std::string>{}(_tc.name_);
    }
};

#endif
