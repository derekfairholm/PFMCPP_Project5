#pragma once

#include "LeakedObjectDetector.h"
#include <vector>
#include "Circle.h"

struct Shape 
{
    Shape();
    ~Shape();

    std::vector<Circle> circles;

    JUCE_LEAK_DETECTOR(Shape)
};
