/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */
 
#include <iostream>
#include "LeakedObjectDetector.h"
#include "House.h"
#include "Job.h"
#include "Circle.h"
#include "Person.h"
#include "Shape.h"
#include "Wrappers.h"

//================================================================

int main()
{
    //1
    std::cout << "-----------UTD: House---------------" << std::endl;
    HouseWrapper houseWrapper(new House);
    std::cout << "This house has " << houseWrapper.pointerToHouse->numberOfBedrooms << " bedrooms and " << houseWrapper.pointerToHouse->numberOfBathrooms << " bathrooms." << std::endl;
    houseWrapper.pointerToHouse->numberBedsAndBaths();
    std::cout << "Estimated mortgage payment: $" << houseWrapper.pointerToHouse->estimatedMortgagePayment( 0.042, 30, 20000 ) << std::endl;
    houseWrapper.pointerToHouse->printEstimatedMortgagePayment();
    
    //2
    std::cout << "-----------UTD: Job---------------" << std::endl;
    JobWrapper jobWrapper(new Job);
    std::cout << "Value of benefits is: $" << jobWrapper.pointerToJob->monetaryValueOfBenefits() << std::endl;
    jobWrapper.pointerToJob->printMonetaryValueOfBenefits();

    //3
    std::cout << "-----------UTD: Circle---------------" << std::endl;
    CircleWrapper circleWrapper(new Circle(5, 10, 10));
    std::cout << "The diameter is: " << circleWrapper.pointerToCircle->diameter << " and the circumference is: " << circleWrapper.pointerToCircle->getCircumference() << std::endl;
    circleWrapper.pointerToCircle->printCircumference();
    std::cout << "Area is: " << circleWrapper.pointerToCircle->getArea() << std::endl;
    circleWrapper.pointerToCircle->printArea();

    //4
    std::cout << "-----------UTD: Person---------------" << std::endl;
    PersonWrapper personWrapper(new Person);

    //5
    std::cout << "-----------UTD: Shape---------------" << std::endl;
    ShapeWrapper shapeWrapper(new Shape);
    std::cout << "good to go!" << std::endl;
    std::cout << "-----------UTD Deconstructors---------------" << std::endl;
}
