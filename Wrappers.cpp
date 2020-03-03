#include "Wrappers.h"
#include "Job.h"
#include "Circle.h"
#include "Person.h"
#include "Shape.h"

HouseWrapper::HouseWrapper(House* ptr) : pointerToHouse(ptr) { }
HouseWrapper::~HouseWrapper() { delete pointerToHouse; }
 
JobWrapper::JobWrapper(Job* ptr) : pointerToJob(ptr) { }
JobWrapper::~JobWrapper() { delete pointerToJob; }

CircleWrapper::CircleWrapper(Circle* ptr) : pointerToCircle(ptr) { }
CircleWrapper::~CircleWrapper() { delete pointerToCircle; }

PersonWrapper::PersonWrapper(Person* ptr) : pointerToPerson(ptr) { }
PersonWrapper::~PersonWrapper() { delete pointerToPerson; }

ShapeWrapper::ShapeWrapper(Shape* ptr) : pointerToShape(ptr) { }
ShapeWrapper::~ShapeWrapper() { delete pointerToShape; }


