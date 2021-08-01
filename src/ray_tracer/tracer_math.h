#ifndef TRACER_MATH_H
#define TRACER_MATH_H

enum TupleType {
	POINT,
	VECTOR
};

class Tuple {
	public:
		float x_;
		float y_;
		float z_;
		TupleType type_;
	
		Tuple(float x, float y, float z, TupleType type);
};


#endif
