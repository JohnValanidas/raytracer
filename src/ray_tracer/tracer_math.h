#ifndef TRACER_MATH_H
#define TRACER_MATH_H

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


		static Tuple vector(float x, float y, float z);
		static Tuple point(float x, float t, float z);
};



#endif
