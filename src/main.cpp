#include <iostream>
#include "./ray_tracer/tracer_math.h"
using namespace std;

class Projectile {
	public:
		Tuple  velocity_;
		Tuple positon_;

		Projectile(Tuple vector, Tuple positon) {
			velocity_ = vector;
			positon_ = positon;
		}
};

class Environment {
	public:
		Tuple gravity_;
		Tuple wind_;
	
		Environment(Tuple gravity, Tuple wind) {
			gravity_ = gravity;
			wind_ = wind;
		}
};


void tick(Environment environment, Projectile &projectile) {
	projectile.positon_ = projectile.positon_ + projectile.velocity_;
	projectile.velocity_ = projectile.velocity_ + environment.gravity_ + environment.wind_;
}


int main() {
	double TICK_RATE = 0.01;

	Projectile rock(Tuple::vector(10,5,0), Tuple::point(0,0,0));
	Environment environment(Tuple::vector(0,-0.1,0), Tuple::vector(-.01,.05,0));

	double time = 0.0;

	while(rock.positon_.y_ >= 0) {
		cout << "Position of rock (" << rock.positon_.x_ << "," << rock.positon_.y_ << ") " << endl;
		tick(environment, rock);
		time += TICK_RATE;
	}

	return 0;
}
