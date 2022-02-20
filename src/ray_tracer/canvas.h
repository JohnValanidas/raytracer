#ifndef CANVAS_H
#define CANVAS_H

#include "tracer_math.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>

class Canvas {
    public:
        int width_;
        int height_;
        Tuple **pixels_;

        Canvas(int width, int height) : Canvas(width, height, Tuple::color(0,0,0) ) {};
        Canvas(int width, int height, Tuple defaultColor);
        ~Canvas();
        void writePixel(int x, int y, Tuple color) const;
        Tuple getPixel(int x, int y) const;

        // print to file
        std::string constructPPMHeader() const;
        std::string constructPPMPixelData() const;
        void savePPMData(const std::string& filename) const;

    private:
        const std::string CANVAS_PPM_VALUE = "P3";

        static float clamp(float num, float min, float max);
};

#endif