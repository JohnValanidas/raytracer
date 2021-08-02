#include "tracer_math.h"

#include <gtest/gtest.h>

TEST(TupleConstuctorPointTest, BasicAssertions) {
	Tuple a(4.3, -4.2, 3.1, POINT);
	EXPECT_NEAR(a.x_, 4.3, 0.00001);
	EXPECT_NEAR(a.y_, -4.2, 0.00001);
	EXPECT_NEAR(a.z_, 3.1, 0.00001);
	EXPECT_EQ(a.type_, POINT);
}



TEST(TupleConstructorVectorTest, BasicAssertions) {
	Tuple b(4.5, 4.2, 3.1, VECTOR);
	EXPECT_NEAR(b.x_, 4.5, 0.00001);
	EXPECT_NEAR(b.y_, 4.2, 0.00001);
	EXPECT_NEAR(b.z_, 3.1, 0.00001);
	EXPECT_EQ(b.type_, VECTOR);
}


TEST(VectorCreationTest, BasicAssertions) {
	Tuple vector = Tuple::vector(1,3,5);
	EXPECT_NEAR(vector.x_, 1, 0.00001);
	EXPECT_NEAR(vector.y_, 3, 0.00001);
	EXPECT_NEAR(vector.z_, 5, 0.00001);
	EXPECT_EQ(vector.type_, VECTOR);
}


TEST(PointCreationTest, BasicAssertions) {
	Tuple point = Tuple::point(34.453, 43, -34);
	EXPECT_NEAR(point.x_, 34.453, 0.00001);
	EXPECT_NEAR(point.y_, 43, 0.0001);
	EXPECT_NEAR(point.z_, -34, 0.00001);
	EXPECT_EQ(point.type_, POINT);
}
