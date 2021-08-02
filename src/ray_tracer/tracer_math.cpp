#include "tracer_math.h"

Tuple::Tuple(float x, float y, float z, TupleType type) {
	x_ = x;
	y_ = y;
	z_ = z;
	type_ = type;

}


Tuple Tuple::vector(float x, float y, float z) {
	return Tuple(x, y, z, VECTOR);
}

Tuple Tuple::point(float x, float y, float z) {
	return Tuple(x, y, z, POINT);
}
