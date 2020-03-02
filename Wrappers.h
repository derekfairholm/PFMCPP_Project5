#pragma once 

#include "House.h"
#include "Job.h"
#include "Circle.h"
#include "Person.h"
#include "Shape.h"

struct HouseWrapper
{
    HouseWrapper(House* ptr);
    ~HouseWrapper();

    House* pointerToHouse = nullptr;
}; 

struct JobWrapper
{
    JobWrapper(Job* ptr);
    ~JobWrapper();

    Job* pointerToJob = nullptr;
};

struct CircleWrapper
{
    CircleWrapper(Circle* ptr);
    ~CircleWrapper();

    Circle* pointerToCircle = nullptr;
};

struct PersonWrapper
{
    PersonWrapper(Person* ptr);
    ~PersonWrapper();

    Person* pointerToPerson = nullptr;
};

struct ShapeWrapper
{
    ShapeWrapper(Shape* ptr);
    ~ShapeWrapper();

    Shape* pointerToShape = nullptr;
};


