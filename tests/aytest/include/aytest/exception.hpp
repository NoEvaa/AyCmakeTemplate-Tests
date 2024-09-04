#ifndef AYTEST_EXCEPTION_HPP_
#define AYTEST_EXCEPTION_HPP_

#include <string>

namespace aytest {

inline std::string getExceptionInfo() {
    try {
        auto ep = std::current_exception();
        if (ep) {
            std::rethrow_exception(ep);
        }
    } catch (std::exception const & e) {
        return e.what();
    } catch (...) {
        return "Unknown exception.";
    }
    return "";
}

}

#endif
