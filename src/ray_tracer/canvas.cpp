#include "canvas.h"

Canvas::Canvas(int width, int height, Tuple defaultColor) {
    width_ = width;
    height_ = height;

    pixels_ = new Tuple*[width_];
    for (int i = 0; i < width_; i++) {
        pixels_[i] = new Tuple[height_];
    }

    // initialize all to color(0,0,0)
    for(int i = 0; i < width_; i++) {
        for(int j = 0; j < height_; j++) {
            pixels_[i][j] = defaultColor;
        }
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < width_; i++) {
        delete[] pixels_[i];
    }
    delete[] pixels_;
}


void Canvas::writePixel(int x, int y, Tuple color) const {
    if (x >= width_ || y >= height_ || x < 0 || y < 0) {
        return;
    }
    pixels_[x][y] = color;
}

Tuple Canvas::getPixel(int x, int y) const {
    if (x >= width_ || y >= height_ || x < 0 || y < 0) {
        return Tuple::color(0,0,0);
    }
    return pixels_[x][y];
}


std::string Canvas::constructPPMHeader() const {
    std::string header;
    header += CANVAS_PPM_VALUE + "\n";
    header += std::to_string(width_) + " " + std::to_string(height_) + "\n";
    header += "255\n";
    return header;
}

std::string Canvas::constructPPMPixelData() const {
    std::string pixelData;
    for(int i = 0; i < height_; i++) {
        // PPM files cannot exced 70 characters in length per line
        int charCount = 0;

        for(int j = 0; j < width_; j++) {
            // clamp each pixel data from 0 to 255
            int red = clamp(pixels_[j][i].x_ * 255, 0, 255);
            int green = clamp(pixels_[j][i].y_ * 255, 0, 255);
            int blue = clamp(pixels_[j][i].z_ * 255, 0, 255);
            
            
            std::string pixel = std::to_string(red) + " " + std::to_string(green) + " " + std::to_string(blue);
            charCount += pixel.length();

            pixelData += std::to_string(red) + " " + std::to_string(green) + " " + std::to_string(blue) + " ";

            // if (charCount >= 67) {
            //     pixelData += "\n";
            //     charCount = 0;
            // }
        }
        pixelData += "\n";
    }
    return pixelData;
}

void Canvas::savePPMData(const std::string& filename) const {
    std::fstream outputFile;

    outputFile.open(filename, std::ios::out);
    if(!outputFile) { // file couldn't be opened
        std::cerr << "Cannot open " << filename << std::endl;
        exit(1);
    }

    outputFile << this->constructPPMHeader();
    outputFile << this->constructPPMPixelData() << std::endl;
    outputFile.close();
}

float Canvas::clamp(float num, float min, float max) {
    const float t = num < min ? min : num;
    return t > max ? max : t;
}