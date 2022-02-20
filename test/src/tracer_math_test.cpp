#include "tracer_math.h"
#include <gtest/gtest.h>

const float EPSILON = 0.00001;

TEST(Tuple, PointTypeConstructor) {
	Tuple a(4.3, -4.2, 3.1, POINT);
	EXPECT_NEAR(a.x_, 4.3, EPSILON);
	EXPECT_NEAR(a.y_, -4.2, EPSILON);
	EXPECT_NEAR(a.z_, 3.1, EPSILON);
	EXPECT_EQ(a.type_, POINT);
}



TEST(Tuple, VectorTypeConstructor) {
	Tuple b(4.5, 4.2, 3.1, VECTOR);
	EXPECT_NEAR(b.x_, 4.5, EPSILON);
	EXPECT_NEAR(b.y_, 4.2, EPSILON);
	EXPECT_NEAR(b.z_, 3.1, EPSILON);
	EXPECT_EQ(b.type_, VECTOR);
}


TEST(Tuple, VectorCreationFunction) {
	Tuple vector = Tuple::vector(1,3,5);
	EXPECT_NEAR(vector.x_, 1, EPSILON);
	EXPECT_NEAR(vector.y_, 3, EPSILON);
	EXPECT_NEAR(vector.z_, 5, EPSILON);
	EXPECT_EQ(vector.type_, VECTOR);
}


TEST(Tuple, PointCreationFunction) {
	Tuple point = Tuple::point(34.453, 43, -34);
	EXPECT_NEAR(point.x_, 34.453, EPSILON);
	EXPECT_NEAR(point.y_, 43, EPSILON);
	EXPECT_NEAR(point.z_, -34, EPSILON);
	EXPECT_EQ(point.type_, POINT);
}

TEST(Tuple, ExceptionOnPointAdd) {
	Tuple point1 = Tuple::point(1,5,9);
	Tuple point2 = Tuple::point(1,1,1);
	try {
		point1 = point1 + point2;
		FAIL() << "Expected std::exception";
	}
	catch(std::invalid_argument const& error) {
		EXPECT_EQ(error.what(), std::string("can not add points together"));
	}
	catch(...) {
		FAIL() << "Expected std::exception";
	}
}

TEST(Tuple, VectorAddition) {
	Tuple vector1 = Tuple::vector(1,5,9);
	Tuple vector2 = Tuple::vector(1,1,1);
	vector1 = vector1 + vector2;
	EXPECT_NEAR(vector1.x_, 2, EPSILON);
	EXPECT_NEAR(vector1.y_, 6, EPSILON);
	EXPECT_NEAR(vector1.z_, 10, EPSILON);
	EXPECT_EQ(vector1.type_, VECTOR);
}

TEST(Tuple, PointVectorAddition) {
	Tuple point = Tuple::point(1,5,9);
	Tuple vector = Tuple::vector(1,1,1);
	point = point + vector;
	EXPECT_NEAR(point.x_, 2, EPSILON);
	EXPECT_NEAR(point.y_, 6, EPSILON);
	EXPECT_NEAR(point.z_, 10, EPSILON);
	EXPECT_EQ(point.type_, POINT);
}

TEST(Tuple, Equailty) {
	Tuple vector1 = Tuple::vector(1,5,9);
	Tuple vector2 = Tuple::vector(1,1,1);
	Tuple vector3 = Tuple::vector(1,1,1);
	if (Tuple::equal(vector1, vector2)) {
		FAIL() << "expect comparision to fail";
	}

	if(!Tuple::equal(vector2, vector3)) {
		FAIL() << "expected comparision to be true";
	}
}

TEST(Tuple, EqualityOperator) {
	Tuple vector1 = Tuple::vector(1,5,9);
	Tuple vector2 = Tuple::vector(1,1,1);
	Tuple vector3 = Tuple::vector(1,1,1);
	if (vector1 == vector2) {
		FAIL() << "expect comparision to fail";
	}
}

TEST(Tuple, NotEqual) {
	Tuple vector1 = Tuple::vector(1,5,9);
	Tuple vector2 = Tuple::vector(1,1,1);
	Tuple vector3 = Tuple::vector(1,1,1);
	if (vector2 != vector3) {
		FAIL() << "expect comparision to fail";
	}
}

TEST(Tuple, Subtraction) {
	Tuple point1 = Tuple::point(1,5,9);
	Tuple point2 = Tuple::point(1,1,1);
	point1 = point1 - point2;
	EXPECT_NEAR(point1.x_, 0, EPSILON);
	EXPECT_NEAR(point1.y_, 4, EPSILON);
	EXPECT_NEAR(point1.z_, 8, EPSILON);
	EXPECT_NEAR(point1.type_, 0, EPSILON);
}

TEST(Tuple, VectorPointSubtraction) {
	Tuple point = Tuple::point(1,5,9);
	Tuple vector = Tuple::vector(1,1,1);
	point = point - vector;
	EXPECT_NEAR(point.x_, 0, EPSILON);
	EXPECT_NEAR(point.y_, 4, EPSILON);
	EXPECT_NEAR(point.z_, 8, EPSILON);
	EXPECT_EQ(point.type_, POINT);
}

TEST(Tuple, VectorSubtraction) {
	Tuple vector = Tuple::vector(1,5,9);
	Tuple vector2 = Tuple::vector(1,1,1);
	vector2 = vector2 - vector;
	EXPECT_NEAR(vector2.x_, 0, EPSILON);
	EXPECT_NEAR(vector2.y_, -4, EPSILON);
	EXPECT_NEAR(vector2.z_, -8, EPSILON);
	EXPECT_EQ(vector2.type_, VECTOR);
}

TEST(Tuple, Negation) {
	Tuple vector = Tuple::vector(1,-2,3);
	vector = -vector;
	EXPECT_NEAR(vector.x_, -1, EPSILON);
	EXPECT_NEAR(vector.y_, 2, EPSILON);
	EXPECT_NEAR(vector.z_, -3, EPSILON);
	EXPECT_EQ(vector.type_, VECTOR);
}

TEST(Tuple, ScalerMultiplication) {
	Tuple tuple = Tuple(1,2,4, POINT);
	tuple = 5*tuple;
	EXPECT_NEAR(tuple.x_, 5, EPSILON);
	EXPECT_NEAR(tuple.y_, 10, EPSILON);
	EXPECT_NEAR(tuple.z_, 20, EPSILON);
	EXPECT_EQ(tuple.type_, POINT);

	Tuple tuple1 = Tuple(1,2,4, POINT);
	tuple1 = tuple1*2;
	EXPECT_NEAR(tuple1.x_, 2, EPSILON);
	EXPECT_NEAR(tuple1.y_, 4, EPSILON);
	EXPECT_NEAR(tuple1.z_, 8, EPSILON);
	EXPECT_EQ(tuple1.type_, POINT);
}


TEST(Tuple, ScalerDivision) {
	Tuple tuple = Tuple(4,2,4, POINT);
	tuple = tuple/2;
	EXPECT_NEAR(tuple.x_, 2, EPSILON);
	EXPECT_NEAR(tuple.y_, 1, EPSILON);
	EXPECT_NEAR(tuple.z_, 2, EPSILON);
	EXPECT_EQ(tuple.type_, POINT);
}

TEST(Tuple, PositiveMagnitude) {
	Tuple vector = Tuple::vector(1, 2, 3);
	float result = vector.magnitude();
	EXPECT_NEAR(result, sqrt(14), EPSILON);
}

TEST(Tuple, NegativeMagnitude) {
	Tuple vector = Tuple::vector(-1, -2, -3);
	float magnitude = vector.magnitude();
	EXPECT_NEAR(magnitude, sqrt(14), EPSILON);
}


TEST(Tuple, Normalization) {
	Tuple vector = Tuple::vector(4,5,4);
	float vectorMagnitude = vector.magnitude();
	Tuple normalized = vector.normalize();
	EXPECT_NEAR(vector.x_/vectorMagnitude, normalized.x_, EPSILON);
	EXPECT_NEAR(vector.y_/vectorMagnitude, normalized.y_, EPSILON);
	EXPECT_NEAR(vector.z_/vectorMagnitude, normalized.z_, EPSILON);
}


TEST(Tuple, Dotproduct) {
	Tuple vectorA = Tuple::vector(1,2,3);
	Tuple vectorB = Tuple::vector(2,3,4);

	float dotProduct = Tuple::dotProduct(vectorA, vectorB);
	EXPECT_NEAR(dotProduct, 20, EPSILON);
}

TEST(Tuple, Crossproduct) {
	Tuple vectorA = Tuple::vector(1,2,3);
	Tuple vectorB = Tuple::vector(2,3,4);

	Tuple aCrossB = Tuple::crossProduct(vectorA, vectorB);
	Tuple bCrossA = Tuple::crossProduct(vectorB, vectorA);

	EXPECT_NEAR(aCrossB.x_, -1, EPSILON);
	EXPECT_NEAR(aCrossB.y_, 2, EPSILON);
	EXPECT_NEAR(aCrossB.z_, -1, EPSILON);

	EXPECT_NEAR(bCrossA.x_, 1, EPSILON);
	EXPECT_NEAR(bCrossA.y_, -2, EPSILON);
	EXPECT_NEAR(bCrossA.z_, 1, EPSILON);

}


TEST(Tuple, Multiplication) {
	Tuple vector1 = Tuple::vector(1, .2, .4);
	Tuple vector2 = Tuple::vector(0.9, 1, 0.1);
	Tuple result = vector1 * vector2;
	EXPECT_NEAR(result.x_, 0.9, EPSILON);
	EXPECT_NEAR(result.y_, 0.2, EPSILON);
	EXPECT_NEAR(result.z_, 0.04, EPSILON);
}

TEST(Tuple, HadamardProduct) {
	Tuple color1 = Tuple::color(1, .5, .25);
	Tuple color2 = Tuple::color(2, 2, 2);
	Tuple result = Tuple::hadamardProduct(color1, color2);

	EXPECT_NEAR(result.x_, 2, EPSILON);
	EXPECT_NEAR(result.y_, 1, EPSILON);
	EXPECT_NEAR(result.z_, .5, EPSILON);
}