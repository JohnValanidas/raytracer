#ifndef TRACER_MATH_H
#define TRACER_MATH_H
#include <stdexcept>
#include <math.h>

enum TupleType {
	VECTOR = 0,
	POINT = 1
};

class Tuple {
	public:
		float x_;
		float y_;
		float z_;
		TupleType type_;
		
		Tuple();
		Tuple(float x, float y, float z, TupleType type);

		float magnitude();
		Tuple normalize();
		
		// Operator Overloading
		Tuple operator+(const Tuple& rhs);
		Tuple operator-(const Tuple& rhs);
		Tuple operator-();
		bool operator==(const Tuple& rhs);
		bool operator!=(const Tuple& rhs);


		static float dotProduct(const Tuple a, const Tuple b);
		static Tuple crossProduct(const Tuple a, const Tuple b);
		static bool equal(const Tuple a, const Tuple b);
		static Tuple vector(float x, float y, float z);
		static Tuple point(float x, float t, float z);
};

Tuple operator*(const float scaler, const Tuple tuple);
Tuple operator*(const Tuple tuple, const float scaler);

Tuple operator/(const Tuple tuple, const float scaler);


#endif
