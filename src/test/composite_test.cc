#include <gtest/gtest.h>
#include "../composite/enum.h"

// Demonstrate some basic assertions.
TEST(enum_Test, enum) {
    spectrum band;
    band = infrared;
    EXPECT_EQ(band,0);
    //band++; cannot increment expression of enum type 'spectrum'
    int color = blue ;
    EXPECT_EQ(color,5);
}