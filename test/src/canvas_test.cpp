#include "canvas.h"
#include <gtest/gtest.h>

const float EPSILON = 0.00001;

//TEST(Sample, BasicAssertions) {
////    FAIL() << "failed";
//}


TEST(Canvas, Constructor) {
    Canvas canvas(10, 20);
    ASSERT_EQ(canvas.width_, 10);
    ASSERT_EQ(canvas.height_, 20);

    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            Tuple color = canvas.pixels_[i][j]; 

            ASSERT_EQ(color.x_, 0);
            ASSERT_EQ(color.y_, 0);
            ASSERT_EQ(color.z_, 0);
            ASSERT_EQ(color.type_, COLOR);
        }
    }
}

TEST(Canvas, WritePixel) {
    Canvas canvas(10, 20);

    Tuple color = Tuple::color(1,.4,.3);

    canvas.writePixel(4, 6, color);

    ASSERT_TRUE(canvas.pixels_[4][6] == color);
}

TEST(Canvas, GetPixel) {
    Canvas canvas(10, 20);

    Tuple color = Tuple::color(1,.4,.3);

    canvas.writePixel(4, 6, color);

    ASSERT_TRUE(canvas.getPixel(4,6) == color);
}

TEST(Canvas, PPMHeader) {
    Canvas canvas(5, 3);
    std::string result = canvas.constructPPMHeader();

    std::string correctHeader = "P3\n5 3\n255\n";

    ASSERT_EQ(result, correctHeader);
}

TEST(Canvas, PPMPixelData) {
    Canvas canvas(5, 3);
    Tuple c1 = Tuple::color(1.5, 0, 0);
    Tuple c2 = Tuple::color(0, .5, 0);
    Tuple c3 = Tuple::color(-.5, 0, 1);

    canvas.writePixel(0, 0, c1);
    canvas.writePixel(2, 1, c2);
    canvas.writePixel(4, 2, c3);
    
    std::string result = canvas.constructPPMPixelData();
    std::string correctPixelData = "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 127 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255 \n";
    ASSERT_EQ(result, correctPixelData);
}

//TEST(CanvasConstructPPMPixelDataCharLimit, BasicAssertions) {
//    Canvas canvas(10, 2);
//    for(int i = 0; i < 10; i++) {
//        for(int j = 0; j < 2; j++) {
//            canvas.writePixel(j, i, Tuple::color(1, .8, .6));
//        }
//    }
//
//    std::string result = canvas.constructPPMPixelData();
//    std::string correctPixelData = "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 \n153 255 204 153 255 204 153 255 204 153 255 204 153 \n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 \n153 255 204 153 255 204 153 255 204 153 255 204 153 \n";
//    ASSERT_EQ(result, correctPixelData);
//}
//
//TEST(CanvasConstructPPMFile, BasicAssertion) {
//
//}