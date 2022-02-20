#include "canvas.h"

float clamp(float d, float min, float max) {
  const float t = d < min ? min : d;
  return t > max ? max : t;
}

//Canvas::Canvas(int width, int height) {
//    this = Canvas(width, height, Tuple::color(0,0,0));
//}

Canvas::Canvas(int width, int height, Tuple defaultColor) {
    width_ = width;
    height_ = height;

    pixels_ = new Tuple*[height_];
    for (int i = 0; i < height_; i++) {
        pixels_[i] = new Tuple[width_];
    }

    // intialize all to color(0,0,0)
    for(int i = 0; i < height_; i++) {
        for(int j = 0; j < width_; j++) {
            pixels_[i][j] = defaultColor;
        }
    }
}

void Canvas::writePixel(int x, int y, Tuple color) {
    pixels_[x][y] = color;
}

Tuple Canvas::getPixel(int x, int y) {
    return pixels_[x][y];
}


std::string Canvas::constructPPMHeader() {
    std::string header = "";
    header += CANVAS_PPM_VALUE + "\n";
    header += std::to_string(width_) + " " + std::to_string(height_) + "\n";
    header += "255\n";
    return header;
}

std::string Canvas::constructPPMPixelData() {
    std::string pixelData = "";
    for(int i = 0; i < height_; i++) {
        // PPM files cannot exced 70 characters in length per line
        int charCount = 0;

        for(int j = 0; j < width_; j++) {
            // clamp each pixel data from 0 to 255
            int red = clamp(pixels_[i][j].x_ * 255, 0, 255);
            int green = clamp(pixels_[i][j].y_ * 255, 0, 255);
            int blue = clamp(pixels_[i][j].z_ * 255, 0, 255);
            
            
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

void Canvas::savePPMData(const std::string& filename) {
    std::fstream outputFile;

    outputFile.open(filename, std::ios::out);
    if( !outputFile ) { // file couldn't be opened
//        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    outputFile << this->constructPPMHeader();
    outputFile << this->constructPPMPixelData() << std::endl;
    outputFile.close();
}

