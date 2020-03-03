#pragma once

#include "LeakedObjectDetector.h"
#include "House.h"
#include "Job.h"

struct Person 
{
    Person();
    ~Person();

    // Member Variables

    House house;
    Job job;

    JUCE_LEAK_DETECTOR(Person)
};
