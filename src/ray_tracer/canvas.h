#ifndef CANVAS_H
#define CANVAS_H

#include "tracer_math.h"
#include <string>
#include <algorithm>
#include <fstream>

const std::string CANVAS_PPM_VALUE = "P3";

class Canvas {
    public:
        int width_;
        int height_;
        Tuple **pixels_;

        Canvas(int width, int height) : Canvas(width, height, Tuple::color(0,0,0) ) {};
        Canvas(int width, int height, Tuple defaultColor);
        void writePixel(int x, int y, Tuple color);
        Tuple getPixel(int x, int y);

        // print to file
        std::string constructPPMHeader();
        std::string constructPPMPixelData();
        void savePPMData(const std::string& filename);
};

#endif