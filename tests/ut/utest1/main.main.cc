#include <aytest/aytest.hpp>
#include <testlib.h>
#include <iostream>

namespace aytest {

enum class ExprHandleMode {
    kCheck = 0,
    kRequire,
};

namespace detail {



template <ExprHandleMode _mode>
struct ExprHandler {
    template <typename... Args>
    bool operator()(Args...) {
        assert(0);
        return false;
    }
};
} // aytest::detail
} // aytest

namespace aytest::detail {



template <>
struct ExprHandler<ExprHandleMode::kCheck> {
    template <typename... Args>
    bool operator()(Args...) {}
};
}
int main()
{
    try{
        throw std::runtime_error("pp");
    }catch(...){
        std::cout << "ex: " << aytest::detail::getExceptionInfo() << std::endl;
    }

    auto fi = aytest::detail::FileInfo(__FILE__, __LINE__);
    std::stringstream ss;
    ss << fi;
    std::cout << ss.str() << std::endl;

    auto& ins = aytest::Singleton<AA>::instance();
    std::cout << ins.a_ << std::endl;
    ins.resetA();
    std::cout << ins.a_ << std::endl;
    return 0;
}
