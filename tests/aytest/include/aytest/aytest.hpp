#ifndef AYTEST_AYTEST_HPP_
#define AYTEST_AYTEST_HPP_

#include <aytest/detail/singleton.hpp>
#include <aytest/detail/file_info.hpp>
#include <aytest/detail/expr_info.hpp>
#include <aytest/detail/expr_eval.hpp>

#define AY_FILEINFO aytest::detail::FileInfo(__FILE__, __LINE__)

#endif
