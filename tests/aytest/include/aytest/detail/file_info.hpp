#ifndef AYTEST_DETAIL_FILE_INFO_HPP_
#define AYTEST_DETAIL_FILE_INFO_HPP_

#include <string>
#include <sstream>

namespace aytest::detail {

struct FileInfo {
    std::string file_;
    std::size_t line_ = 0;

    FileInfo(char const * _file, std::size_t _line) : file_(_file), line_(_line) {}
};

inline std::stringstream & operator<<(std::stringstream & ss, FileInfo const & finfo) {
    ss << finfo.file_ << "(" << finfo.line_ << ")";
    return ss;
}

}

#endif
