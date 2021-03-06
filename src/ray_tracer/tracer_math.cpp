#include "tracer_math.h"

Tuple::Tuple() {
	x_ = 0;
	y_ = 0;
	z_ = 0;
	type_ = VECTOR;
}

Tuple::Tuple(float x, float y, float z, TupleType type) {
	x_ = x;
	y_ = y;
	z_ = z;
	type_ = type;
}

float Tuple::magnitude() {
	return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}

Tuple Tuple::normalize() {
	float mag = magnitude();
	return {x_/mag, y_/mag, z_/mag, type_};

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

Tuple Tuple::operator*(const Tuple &rhs) {
	return {x_ * rhs.x_, y_ * rhs.y_, z_ * rhs.z_, type_};
}


// FIXME: might have to come back and revist the type negation
Tuple Tuple::operator-() {
	return Tuple(-x_, -y_, -z_, type_); 
}


bool Tuple::operator==(const Tuple& rhs) {
	return equal(*this, rhs);
}

bool Tuple::operator!=(const Tuple& rhs) {
	return !equal(*this, rhs);
}


float Tuple::dotProduct(const Tuple a, const Tuple b) {
	return a.x_ * b.x_ + a.y_ * b.y_ + a.z_ * b.z_;
}

Tuple Tuple::crossProduct(const Tuple a, const Tuple b) {
	return vector(a.y_ * b.z_ - a.z_ * b.y_,
				  a.z_ * b.x_ - a.x_ * b.z_,
				 a.x_ * b.y_ - a.y_ * b.x_);
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
	return {x, y, z, VECTOR};
}

Tuple Tuple::point(float x, float y, float z) {
	return {x, y, z, POINT};
}

Tuple Tuple::color(float r, float g, float b) {
	return {r, g, b, COLOR};
}

Tuple Tuple::hadamardProduct(Tuple color1, Tuple color2) {
	if (color1.type_ != COLOR || color2.type_ != COLOR) {
		throw std::invalid_argument("tuple input not of type COLOR");
	}
	return Tuple::color(color1.x_ * color2.x_, color1.y_ * color2.y_, color1.z_ * color2.z_);
}

// Non-member function overloaded operators
Tuple operator*(const float scaler, const Tuple tuple) {
	return Tuple(tuple.x_ * scaler, tuple.y_ * scaler, tuple.z_ * scaler, tuple.type_);
}

Tuple operator*(const Tuple tuple, const float scaler) {
	return Tuple(tuple.x_ * scaler, tuple.y_ * scaler, tuple.z_ * scaler, tuple.type_);
}

Tuple operator/(const Tuple tuple, const float scaler) {
	return Tuple(tuple.x_ / scaler, tuple.y_ / scaler, tuple.z_ / scaler, tuple.type_);
}

