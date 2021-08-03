#ifndef TRACER_MATH_H
#define TRACER_MATH_H
#include <stdexcept>

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
	
		Tuple(float x, float y, float z, TupleType type);
		
		// Operator Overloading
		Tuple operator+(const Tuple& rhs);
		Tuple operator-(const Tuple& rhs);
		bool operator==(const Tuple& rhs);
		bool operator!=(const Tuple& rhs);


		static bool equal(const Tuple a, const Tuple b);
		static Tuple vector(float x, float y, float z);
		static Tuple point(float x, float t, float z);
};



#endif
