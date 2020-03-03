#include "Circle.h"
#include <cmath>

Circle::Circle(double r, double x, double y) : 
    radius(r),
    centerX(x),
    centerY(y)
{ 
    diameter = radius * 2.0; 
}

Circle::~Circle() { }

double Circle::getCircumference() { return M_PI * this->diameter; }

double Circle::getArea() { return M_PI * (pow(radius, 2)); }

void Circle::drawCircle()
{
    std::cout << "Drawing new circle with radius: " << this->radius << std::endl;
    // A hypothetical function that would render a circle with a given radius.
}

void Circle::drawConcentricCircles(double startingRadius, double maxRadius, double numberOfCircles, double centerX_, double centerY_)
{
    double currentRadius = startingRadius;
    double increment = (maxRadius - startingRadius) / (numberOfCircles - 1.0);

    while (currentRadius <= maxRadius + 0.0001)
    {
        Circle c(currentRadius, centerX_, centerY_);
        c.drawCircle();
        currentRadius += increment;
    }
}

void Circle::printCircumference()
{
    std::cout << "The diameter is: " << this->diameter << " and the circumference is: " << this->getCircumference() << std::endl;
}

void Circle::printArea() { std::cout << "Area is: " << this->getArea() << std::endl; }

