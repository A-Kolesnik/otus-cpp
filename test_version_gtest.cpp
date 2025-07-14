#include <gtest/gtest.h>
#include "lib.h"

TEST(GeneralTests, VesionTestingGTest){
    EXPECT_GT(version(), 0);
}
