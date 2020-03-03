#pragma once

#include "LeakedObjectDetector.h"

struct Circle
{
    Circle(double r, double x, double y);
    ~Circle();

    // Member Functions

    double getCircumference();
    double getArea();
    void drawCircle();
    void drawConcentricCircles(double startingRadius, double maxRadius, double numberOfCircles, double centerX_, double centerY_);
    void printCircumference();
    void printArea();

    // Member Variables

    double radius;
    double diameter;
    double centerX;
    double centerY;

    JUCE_LEAK_DETECTOR(Circle)
};
