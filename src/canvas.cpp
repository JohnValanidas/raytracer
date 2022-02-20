#include "ray_tracer/canvas.h"
#include <iostream>

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
    Canvas canvas(900, 800, Tuple::color(0,0,0));

    Projectile rock( (Tuple::vector(.5, 4, 0).normalize()) * 5.25, Tuple::point(0,0,0));
    Environment environment(Tuple::vector(0,-0.005,0), Tuple::vector(.000, -.02,0));


    while(rock.positon_.y_ >= 0) {
        tick(environment, rock);
        // coords are from top left down for Y to fix we subtract the height
        canvas.writePixel( int(rock.positon_.x_), int(canvas.height_ - rock.positon_.y_), Tuple::color(0,0,1));
    }

    canvas.savePPMData("projectile.ppm");
    return 0;
}