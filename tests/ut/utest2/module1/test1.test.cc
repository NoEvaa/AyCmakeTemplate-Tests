#include "testlib.h"
#include "utest2/utils.h"

TEST_CASE("module1 test1 case1") {
    CHECK(pow3(1) == 1);
    CHECK(pow3(2) == 8);
    CHECK(pow3(10) == 1000);
}

