#include "testlib.h"

TEST_CASE("module1 test2 case1") {
    REQUIRE(pow2(1) == 1);
    CHECK(pow2(2) == 4);
    CHECK(pow2(10) == 100);
}

