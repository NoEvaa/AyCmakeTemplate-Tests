#ifndef AYTEST_DETAIL_EXPR_INFO_HPP_
#define AYTEST_DETAIL_EXPR_INFO_HPP_

#include <functional>
#include <string>
#include <sstream>
#include <cassert>

namespace aytest::detail {

struct ExprInfo {
    std::function<bool(void)> fn_;
    
    std::string expr_str_;
    std::string handle_str_;

    ExprInfo(std::function<bool(void)> _fn, char const * _expr, char const * _handle)
        : fn_(_fn), expr_str_(_expr), handle_str_(_handle) {}

    operator bool() const {
        assert(fn_);
        return bool(fn_);
    }

    bool operator()() const {
        assert(fn_);
        return fn_();
    }
};

inline std::stringstream & operator<<(std::stringstream & ss, ExprInfo const & einfo) {
    ss << einfo.handle_str_ << "( " << einfo.expr_str_ << " )";
    return ss;
}

}

#endif
