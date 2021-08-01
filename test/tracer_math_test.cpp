#include "../tracer_math.h"

#include <gtest/gtest.h>


TEST(HelloTest, BasicAssertions) {
	EXPECT_STRNE("Hello", "world");
	EXPECT_EQ(7*6, 42);
}


TEST(TupleTest, BasicAssertions) {
	Tuple a(4.3, -4.2, 3.1, POINT);
	EXPECT_EQ(a.x_, 4.3);
	EXPECT_EQ(a.y_, -4.2);
	EXPECT_EQ(a.z_, 3.1);
	EXPECT_EQ(a.type_, POINT);
}

