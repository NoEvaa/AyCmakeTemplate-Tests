#ifndef AYTEST_DETAIL_EXPR_EVAL_HPP_
#define AYTEST_DETAIL_EXPR_EVAL_HPP_

#include <aytest/detail/constant.hpp>
#include <aytest/detail/file_info.hpp>
#include <aytest/detail/expr_info.hpp>
#include <aytest/detail/exception.hpp>

namespace aytest {
enum class ExprEvalMode {
    kCondition = 0,
    kThrow,
    kNoThrow,
};

namespace detail {
template <ExprEvalMode _mode>
struct ExprEval {
    template <typename... Args>
    bool operator()(Args...) {
        assert(0);
        return false;
    }
};

inline void _evalExprFailed(std::stringstream & ss, ExprInfo const & _expr,
                            FileInfo const & _finfo) {
    ss << _finfo << ": " << std::endl;
    ss << kTabStr << _expr << std::endl << std::endl;
}

template <>
struct ExprEval<ExprEvalMode::kCondition> {
    template <typename... Args>
    bool operator()(std::stringstream & ss, ExprInfo const & _expr,
                    FileInfo const & _finfo, Args...) {
        if (!_expr) {
            return false;
        }
        if (_expr()) {
            return true;
        }
        _evalExprFailed(ss, _expr, _finfo);
        return false;
    }
};

template <>
struct ExprEval<ExprEvalMode::kThrow> {
    template <typename... Args>
    bool operator()(std::stringstream & ss, ExprInfo const & _expr,
                    FileInfo const & _finfo, Args...) {
        if (!_expr) {
            return false;
        }
        try {
            _expr();
            _evalExprFailed(ss, _expr, _finfo);
            return false;
        } catch (...) {
            return true;
        }
        assert(0);
        return false;
    }
};

template <>
struct ExprEval<ExprEvalMode::kNoThrow> {
    template <typename... Args>
    bool operator()(std::stringstream & ss, ExprInfo const & _expr,
                    FileInfo const & _finfo, Args...) {
        try {
            _expr();
            return true;
        } catch (...) {
            ss << _finfo << ": " << std::endl;
            ss << kTabStr << getExceptionInfo() << std::endl << std::endl;
            return false;
        }
        assert(0);
        return false;
    }
};
} // aytest::detail
} // aytest

#endif
