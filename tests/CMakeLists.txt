# Tests
#

# You can use other test framework here,
# such as `catch2`/`gtest`...
add_subdirectory(aytest)

# Link test framework and the module to test here.
add_subdirectory(testlib)

# Unit test
add_subdirectory(ut)
