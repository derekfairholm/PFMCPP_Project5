#include "Shape.h"

Shape::Shape() 
{
    circles =
    {
        Circle(4,6,8), 
        Circle(2,3,7),
        Circle(6,8,2)
    };
}

Shape::~Shape() 
{
    std::cout << "This shape contained " << this->circles.size() << " cirlces." << std::endl;
}

