#include "tracer_math.h"

Tuple::Tuple(float x, float y, float z, TupleType type) {
	x_ = x;
	y_ = y;
	z_ = z;
	type_ = type;
}

Tuple Tuple::operator+(const Tuple& rhs) {
	if (rhs.type_ == POINT && type_ == POINT) {
		throw std::invalid_argument("can not add points together");
	}
	TupleType newType = type_ > rhs.type_ ? type_ : rhs.type_;
	return Tuple(rhs.x_ + x_, rhs.y_ + y_, rhs.z_ + z_, newType);
}

Tuple Tuple::operator-(const Tuple& rhs) {
	Tuple copy(x_, y_, z_, type_);
	copy.x_ -= rhs.x_;
	copy.y_ -= rhs.y_;
	copy.z_ -= rhs.z_;
	copy.type_ = TupleType(copy.type_ - rhs.type_);
	return copy;
}

bool Tuple::operator==(const Tuple& rhs) {
	return equal(*this, rhs);
}

bool Tuple::operator!=(const Tuple& rhs) {
	return !equal(*this, rhs);
}


bool Tuple::equal(const Tuple a, const Tuple b) {
	if (a.x_ == b.x_ &&
		a.y_ == b.y_ &&
		a.z_ == b.z_ &&
		a.type_ == b.type_) {
			return true;
		}
	return false;
}

Tuple Tuple::vector(float x, float y, float z) {
	return Tuple(x, y, z, VECTOR);
}

Tuple Tuple::point(float x, float y, float z) {
	return Tuple(x, y, z, POINT);
}
