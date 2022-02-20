#include "ray_tracer/canvas.h"


int main() {
    Canvas canvas(1000, 1000, Tuple::color(1,0,0));
    canvas.savePPMData("output.ppm");
    return 0;
}